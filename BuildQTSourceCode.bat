echo off
echo Setting up environment for Qt Building usage...
set path=
set include=
set lib=
set QTDIR=E:\QTSourceCode\qt
set path=C:\MinGW\mingw32\bin;C:\MinGW\bin;C:\MinGW;C:\Perl\bin;%QTDIR%;%QTDIR%\bin;%PATH%
set include=C:\MinGW\mingw32\include;C:\Mysql\include
set lib=C:\MinGW\mingw32\lib;C:\Mysql\lib
set QMAKESPEC=win32-g++
