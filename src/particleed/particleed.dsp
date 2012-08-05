# Microsoft Developer Studio Project File - Name="particleed" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=particleed - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "particleed.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "particleed.mak" CFG="particleed - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "particleed - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "particleed - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "particleed - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /QIfist /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 user32.lib gdi32.lib advapi32.lib shell32.lib winmm.lib opengl32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "particleed - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /QIfist /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 user32.lib gdi32.lib advapi32.lib shell32.lib winmm.lib opengl32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "particleed - Win32 Release"
# Name "particleed - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\commands.cpp
# End Source File
# Begin Source File

SOURCE=.\particleed.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\particleed.h
# End Source File
# End Group
# Begin Group "HGE"

# PROP Default_Filter ""
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "core"

# PROP Default_Filter ""
# Begin Group "bass"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\core\BASS\bass.h
# End Source File
# End Group
# Begin Group "zlib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\core\ZLIB\adler32.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\crc32.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\crc32.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\crypt.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\deflate.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\inffast.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\inffast.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\inffixed.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\inflate.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\inflate.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\inftrees.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\inftrees.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\ioapi.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\ioapi.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\trees.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\trees.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\uncompr.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\unzip.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\unzip.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\zconf.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\zconf.in.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\zip.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\zlib.h
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\zutil.c
# End Source File
# Begin Source File

SOURCE=..\core\ZLIB\zutil.h
# End Source File
# End Group
# Begin Group "soil"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\core\soil\image_DXT.cpp
# End Source File
# Begin Source File

SOURCE=..\core\soil\image_DXT.h
# End Source File
# Begin Source File

SOURCE=..\core\soil\image_helper.cpp
# End Source File
# Begin Source File

SOURCE=..\core\soil\image_helper.h
# End Source File
# Begin Source File

SOURCE=..\core\soil\SOIL.cpp
# End Source File
# Begin Source File

SOURCE=..\core\soil\SOIL.h
# End Source File
# Begin Source File

SOURCE=..\core\soil\stb_image_aug.cpp
# End Source File
# Begin Source File

SOURCE=..\core\soil\stb_image_aug.h
# End Source File
# Begin Source File

SOURCE=..\core\soil\stbi_DDS_aug.h
# End Source File
# Begin Source File

SOURCE=..\core\soil\stbi_DDS_aug_c.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\core\demo.cpp
# End Source File
# Begin Source File

SOURCE=..\core\dx2ogl.h
# End Source File
# Begin Source File

SOURCE=..\core\graphics.cpp
# End Source File
# Begin Source File

SOURCE=..\core\hge_impl.h
# End Source File
# Begin Source File

SOURCE=..\core\ini.cpp
# End Source File
# Begin Source File

SOURCE=..\core\input.cpp
# End Source File
# Begin Source File

SOURCE=..\core\power.cpp
# End Source File
# Begin Source File

SOURCE=..\core\random.cpp
# End Source File
# Begin Source File

SOURCE=..\core\resource.cpp
# End Source File
# Begin Source File

SOURCE=..\core\sound.cpp
# End Source File
# Begin Source File

SOURCE=..\core\system.cpp
# End Source File
# Begin Source File

SOURCE=..\core\timer.cpp
# End Source File
# End Group
# Begin Group "helpers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\helpers\hgeanim.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgecolor.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgedistort.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgefont.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgegui.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgeguictrls.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgeparticle.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgepmanager.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgerect.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgeresource.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgesprite.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgestrings.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\hgevector.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\parser.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\parser.h
# End Source File
# Begin Source File

SOURCE=..\helpers\resources.cpp
# End Source File
# Begin Source File

SOURCE=..\helpers\resources.h
# End Source File
# End Group
# End Group
# Begin Group "include"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\include\hge.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgeanim.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgecolor.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgedistort.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgefont.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgegui.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgeguictrls.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgeparticle.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgerect.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgeresource.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgesprite.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgestrings.h
# End Source File
# Begin Source File

SOURCE=..\..\include\hgevector.h
# End Source File
# End Group
# End Group
# End Target
# End Project
