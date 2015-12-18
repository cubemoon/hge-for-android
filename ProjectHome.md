# Introduction #
HGE engine (1.8.1) now can work both on Win32 and Android in same code base.
I port HGE to run with OpenGLES 1.1 and use SDL to make it run multi-platform.
Now, all samples from original hge engine work fine on Win32 and Android.

# Status #
### Win32 ###
Same as HGE original version
### Android ###
-Run with all sample from original hge engine

-No sound (i don't use BASS lib, i will use SDL\_MIXER)

### IOS ###
-Will support in near future.
# How to build #
### Win32 ###

--Open .\tutorials\tutorial01\hge\_tut01.sln

--Set Working Directory to .\tutorials\Runtime

--Build and Run
### Android ###
Compile

--Install Android NDK, Android SDK , Cygwin and apache-ant-1.8.2

--Set correct path in file .\tutorials\Android\CompileNativeCode.bat

--Call CompileNativeCode.bat to compile native code

--Call MakeDebug.bat to make apk file

Run

--Copy all data from folder Runtime to folder Sdcard\HGE

--Install apk file and Run :D


# ScreenShot #
<a href='http://imageshack.us/photo/my-images/337/cimg0008ph.jpg/' title='ImageShack - Image And Video Hosting'><img src='http://img337.imageshack.us/img337/5944/cimg0008ph.jpg' border='0' /></a>
# Support #
-if you want to contribute some code, make some improvements please contact me by e-mail (nguyenhoangtuvn@gmail.com)
# HGE homepage #
You can get Win32 code and community support at http://hge.relishgames.com/