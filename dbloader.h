
#ifndef _H_DBLOADER
#define _H_DBLOADER

#include <QString>
#include <QSqlDatabase>

#include <memory>


class DBLoader {
public:
  DBLoader();
  DBLoader( const DBLoader& );
  DBLoader( const QString& dbloc, const QString& pass ="" );
  DBLoader& operator=( const DBLoader& orig );

  virtual ~DBLoader(){}

  /**
   * @brief does this dbloc require a password
   * @return false
   */
  static bool needsPassphrase( const QString& dbloc );

  /**
   * @brief loads the dbloc data and returns an engine, or null
   * if the db cannot be opened.
   * @param dbloc
   * @param pass
   * @return
   */
  static std::unique_ptr<QHacc> load( const QString& dbloc,
                                      bool createIfMissing,
                                      const QString& pass = "" );

  virtual bool save() =0;
  void setPassword( const QString& pass );
  void setLocation( const QString& dbloc );

protected:
  QString location;
  QString password;

  virtual QSqlDatabase iload( const QString& dbloc, bool createIfMissing,
                              const QString& pass ) =0;
  const QString& pass() const {
    return password;
  }

  static bool create( QSqlDatabase& db );
  
  static bool runsql( QSqlDatabase& db, const QString& resource );
};
















#endif