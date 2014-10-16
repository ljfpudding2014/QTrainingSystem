/************************* * * * * * * * * * * * * ***************************
    Copyright (c) 1999-2014 Ryan Bobko
                       ryan@ostrich-emulators.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************** * * * * * * * * * * * * **************************/


#include "Logger.h"

#include <iostream>
using namespace std;

Logger * Logger::me = 0;

Logger::Logger( ) {
  level = Info;
}

Logger & Logger::instance( ) {
  if ( 0 == me ) me = new Logger( );
  return *me;
}

void Logger::error( const QString& out ) {
  instance( ).log( out, Error );
}

void Logger::debug( const QString& out ) {
  instance( ).log( out, Debug );
}

void Logger::warn( const QString& out ) {
  instance( ).log( out, Warn );
}

void Logger::info( const QString& out ) {
  instance( ).log( out, Info );
}

void Logger::fatal( const QString& out ) {
  instance( ).log( out, Fatal );
}

void Logger::none( const QString& out ) {
  instance( ).log( out, None );
}

void Logger::setLevel( LogLevel lev ) {
  instance( ).setLev( lev );
}

void Logger::setLev( LogLevel lev ) {
  level = lev;
}

void Logger::log( const QString& out, LogLevel l ) const {
  if ( l > level || None == l ) {
    return;
  }

  static const char * TAGS[] = { "", "FATAL", "ERROR", "WARN ", "INFO ", "DEBUG",
    "ALL  " };


  cout << "[" << TAGS[(int) l] << "] " << qPrintable( out ) << std::endl;
}
