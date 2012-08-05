@echo off
rem ********************************************
rem 	Set Environment
rem ********************************************
set ANDROID_HOME=y:\android-sdk-windows\
set ANDROID_NDK_HOME=y:\android-ndk-r7\
set CYGWIN_BIN=y:\cywin\bin
set APACHE_ANT=y:\apache-ant-1.8.0\bin

set CYGWIN_BASH=%CYGWIN_BIN%\bash.exe
rem suppress dos warning path on CYGWIN
set CYGWIN=nodosfilewarning
rem add CYGWIN to PATH
set PATH=%CYGWIN_BIN%;%PATH%
rem ndk-build bash
set NDK_BUILD=%ANDROID_NDK_HOME%/ndk-build

rem number processor use for compile 
set NUMBER_OF_PROCESSORS=2


rem ********************************************
rem 	Build
rem ********************************************

set CUR_DIR=%CD%

call %CYGWIN_BIN%\bash.exe -i %ANDROID_NDK_HOME%/ndk-build -j %NUMBER_OF_PROCESSORS%

echo Compiling done!