echo off
echo Setting up environment for C++ 11 with Minw32 GCC 4.8.1 usage...
set path=
set include=
set lib=
set path=C:\MinGW\bin;C:\MinGW\libexec\gcc\mingw32\4.8.1;%PATH%
set LIBRARY_PATH=C:\MinGW\lib;C:\MinGW\mingw32\lib\gcc\mingw32\4.8.1;
set C_INCLUDE_PATH=c:\MinGW\include;C:\MinGW\mingw32\lib\gcc\mingw32\4.8.1\include;
set CPLUS_INCLUDE_PATH=c:\MinGW\include;C:\MinGW\mingw32\lib\gcc\mingw32\4.8.1\include\c++;C:\MinGW\mingw32\lib\gcc\mingw32\4.8.1\include\c++\backward;C:\MinGW\mingw32\lib\gcc\mingw32\4.8.1\include\c++\mingw32;
