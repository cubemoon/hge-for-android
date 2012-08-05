# Microsoft Developer Studio Project File - Name="hge_tut01" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=hge_tut01 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "hge_tut01.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "hge_tut01.mak" CFG="hge_tut01 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "hge_tut01 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "hge_tut01 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "hge_tut01 - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /QIfist /c
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 opengl32 user32.lib gdi32.lib advapi32.lib shell32.lib winmm.lib opengl32.lib /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "hge_tut01 - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /QIfist /c
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 user32.lib gdi32.lib advapi32.lib shell32.lib winmm.lib opengl32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "hge_tut01 - Win32 Release"
# Name "hge_tut01 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\hge_tut01.cpp
# End Source File
# End Group
# Begin Group "HGE"

# PROP Default_Filter ""
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
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "core"

# PROP Default_Filter ""
# Begin Group "BASS"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\core\BASS\bass.h
# End Source File
# End Group
# Begin Group "ZLIB"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\core\ZLIB\adler32.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\crc32.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\crc32.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\crypt.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\deflate.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\inffast.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\inffast.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\inffixed.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\inflate.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\inflate.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\inftrees.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\inftrees.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\ioapi.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\ioapi.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\trees.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\trees.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\uncompr.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\unzip.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\unzip.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\zconf.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\zconf.in.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\zip.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\zlib.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\zutil.c
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ZLIB\zutil.h
# End Source File
# End Group
# Begin Group "soil"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\core\soil\image_DXT.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\image_DXT.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\image_helper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\image_helper.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\SOIL.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\SOIL.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\stb_image_aug.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\stb_image_aug.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\stbi_DDS_aug.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\soil\stbi_DDS_aug_c.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\src\core\demo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\dx2ogl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\graphics.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\hge_impl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\core\ini.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\input.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\power.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\random.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\resource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\sound.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\system.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\core\timer.cpp
# End Source File
# End Group
# Begin Group "helpers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\helpers\hgeanim.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgecolor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgedistort.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgefont.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgegui.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgeguictrls.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgeparticle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgepmanager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgerect.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgeresource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgesprite.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgestrings.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\hgevector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\parser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\parser.h
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\resources.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\helpers\resources.h
# End Source File
# End Group
# End Group
# End Group
# End Target
# End Project
