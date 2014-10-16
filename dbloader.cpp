
#include "Logger.h"

#include <sys/stat.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QFile>
#include <QSettings>
#include <QProcess>

#include "DBLoader.h"
#include "DefaultQHaccLoader.h"

DBLoader::DBLoader( ) {
}

DBLoader::DBLoader( const DBLoader& orig ) : location( orig.location ),
password( orig.password ) {
}

DBLoader::DBLoader( const QString& loc, const QString& pass ) :
location( loc ), password( pass ) {
}

DBLoader& DBLoader::operator=( const DBLoader& orig ) {
  if ( this != &orig ) {
    location = orig.location;
    password = orig.password;
  }

  return *this;
}

bool DBLoader::needsPassphrase( const QString& dbloc ) {
  return dbloc.startsWith( "ENC:" );
}

std::unique_ptr<QHacc> DBLoader::load( const QString& dbloc,
    bool createIfMissing,
    const QString& pass ) {
  std::unique_ptr<DBLoader> loader;
  if ( dbloc.startsWith( "ENC:" ) ) {
    loader.reset( new GpgQHaccLoader( ) );
  }
  else {
    loader.reset( new DefaultQHaccLoader( ) );
  }

  QSettings settings;
  QString syscmd = settings.value( SystemCommandOnSave, "" ).toString( );
  if ( !syscmd.isEmpty( ) ) {
    QProcess::execute( syscmd, QStringList( "load" ) );
  }

  std::unique_ptr<QHacc> engine;
  QSqlDatabase sqldb = loader->iload( dbloc, createIfMissing, pass );
  if ( sqldb.isOpen( ) ) {
    engine.reset( new QHacc( sqldb, std::move( loader ) ) );
  }

  return std::move( engine );
}

void DBLoader::setPassword( const QString& pass ) {
  password = pass;
}

void DBLoader::setLocation( const QString& dbloc ) {
  location = dbloc;
}

bool DBLoader::runsql( QSqlDatabase& db, const QString& resource ) {
  QFile sqlfile( resource );
  if ( sqlfile.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
    QString sql;
    while ( !sqlfile.atEnd( ) ) {
      QString line = sqlfile.readLine( );
      // remove comments
      if ( line.contains( "--" ) ) {
        int idx = line.indexOf( "--" );
        sql += line.left( idx );
      }
      else {
        sql += line;
      }
    }

    for ( const QString& tstmt : sql.split( ';', QString::SkipEmptyParts ) ) {
      QString stmt = tstmt.simplified( );
      if ( !stmt.isEmpty( ) ) {
        Logger::debug( stmt );
        QSqlQuery q = db.exec( stmt );
        if ( q.lastError( ).isValid( ) ) {
          Logger::error( q.lastError( ).text( ) );
        }
      }
    }

    sqlfile.close( );
    return true;
  }

  return false;
}

bool DBLoader::create( QSqlDatabase& db ) {
  return runsql( db, ":/create.sql" );
}
