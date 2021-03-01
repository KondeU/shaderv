cd %~dp0..

set BUILD_TYPE=%1
set BUILD_BITS=%2
set BUILD_COMPILE=%3

rem script params: msvc.bat [BUILD_TYPE] [BUILD_COMPILE] [BUILD_BITS]
rem default value: BUILD_TYPE=Debug BUILD_COMPILE=VS2015 BUILD_BITS=x86

if "%BUILD_TYPE%"=="" (set BUILD_TYPE=Debug)
if "%BUILD_COMPILE%"=="" (set BUILD_COMPILE=VS2015)

if "%BUILD_COMPILE%"=="VS2015" (set BUILD_COMPILE=Visual Studio 14 2015)
if "%BUILD_COMPILE%"=="VS2017" (set BUILD_COMPILE=Visual Studio 15 2017)
if "%BUILD_COMPILE%"=="VS2019" (set BUILD_COMPILE=Visual Studio 16 2019)

rem configuring qt
if "%QTDIR%"=="" (
if "%BUILD_COMPILE%"=="Visual Studio 14 2015" (set Qt5_DIR=%Qt5_DIR%\msvc2015)
if "%BUILD_COMPILE%"=="Visual Studio 15 2017" (set Qt5_DIR=%Qt5_DIR%\msvc2017)
if "%BUILD_COMPILE%"=="Visual Studio 16 2019" (set Qt5_DIR=%Qt5_DIR%\msvc2017)
)
if "%QTDIR%"=="" (
if "%BUILD_BITS%"=="x64" (set Qt5_DIR=%Qt5_DIR%_64)
)
if "%QTDIR%"=="" (
set Qt5_DIR=%Qt5_DIR%\lib\cmake\Qt5
)
if "%QTDIR%"=="" (
set QTDIR=%Qt5_DIR%\..\..\..
) else (
rem the compiler and compilation environment are limited if QTDIR is specified
set Qt5_DIR=%QTDIR%\lib\cmake\Qt5
)

rem only VS2019 uses "BUILD_ARCH_ARG"
set BUILD_ARCH_ARG=
if "%BUILD_COMPILE%"=="Visual Studio 16 2019" (
if "%BUILD_BITS%"=="x64" (set BUILD_ARCH_ARG=-A x64) ^
else (set BUILD_ARCH_ARG=-A Win32)
) else (
if "%BUILD_BITS%"=="x64" (set BUILD_COMPILE=%BUILD_COMPILE% Win64)
)

if exist "build\dependency" (goto _tag_build_trace_shaderv)

:_tag_build_trace_darkss
rem ===== build trace <3rd: QDarkStyleSheet> =====

mkdir build\dependency\darkss\rc
copy darkss\QDarkStyleSheet-2.8.1\qdarkstyle\style.qrc build\dependency\darkss /Y
copy darkss\QDarkStyleSheet-2.8.1\qdarkstyle\style.qss build\dependency\darkss /Y
xcopy darkss\QDarkStyleSheet-2.8.1\qdarkstyle\rc build\dependency\darkss\rc /E /Y

:_tag_build_trace_qtads
rem ===== build trace <3rd: QtAdvancedDockingSystem> =====

mkdir build\qtads
cd build\qtads
cmake -G "%BUILD_COMPILE%" %BUILD_ARCH_ARG% ^
-DCMAKE_INSTALL_PREFIX=%~dp0..\build\dependency\qtads ^
../../qtads/Qt-Advanced-Docking-System-3.7.1
cmake --build . --config %BUILD_TYPE% -j 8
cmake --install . --config %BUILD_TYPE%
set QADS_BUILD_BITS=%BUILD_BITS%
if not "%BUILD_BITS%"=="x64" (set QADS_BUILD_BITS=Win32)
copy %QADS_BUILD_BITS%\bin\%BUILD_TYPE%\qtadvanceddocking.pdb ^
..\dependency\qtads\bin /Y
cd ..\..

:_tag_build_trace_nodes
rem ===== build trace <3rd: nodeeditor> =====

mkdir build\nodes
cd build\nodes
cmake -G "%BUILD_COMPILE%" %BUILD_ARCH_ARG% -DBUILD_TESTING=OFF ^
-DCMAKE_INSTALL_PREFIX=%~dp0..\build\dependency\nodes ^
../../nodes/nodeeditor-2.1.3
cmake --build . --config %BUILD_TYPE% -j 8
cmake --install . --config %BUILD_TYPE%
mkdir ..\dependency\nodes\bin
copy bin\%BUILD_TYPE%\nodes.dll ..\dependency\nodes\bin /Y
copy bin\%BUILD_TYPE%\nodes.pdb ..\dependency\nodes\bin /Y
cd ..\..

:_tag_build_trace_shaderv
rem ===== build trace <shaderv> =====

mkdir build\shaderv
cd build\shaderv
set BUILD_SHADERV_ARGS=
if "%BUILD_TYPE%"=="Debug" (
set BUILD_SHADERV_ARGS=%BUILD_SHADERV_ARGS% -DSHADERV_USE_CONSOLE=ON
)
::set BUILD_SHADERV_ARGS=%BUILD_SHADERV_ARGS% ^
::-D*_DIR=%~dp0..\build\dependency\qtads\lib\cmake\qtadvanceddocking
set BUILD_SHADERV_ARGS=%BUILD_SHADERV_ARGS% ^
-DNodeEditor_DIR=%~dp0..\build\dependency\nodes\lib\cmake\NodeEditor
cmake -G "%BUILD_COMPILE%" %BUILD_ARCH_ARG% ^
%BUILD_SHADERV_ARGS% ../../shaderv
cmake --build . --config %BUILD_TYPE% -j 8
cd ..\..

:_tag_archive
rem ===== archive trace =====

mkdir build\archive
cd build\archive
copy ..\dependency\qtads\bin\* . /Y
copy ..\dependency\nodes\bin\* . /Y
copy ..\shaderv\%BUILD_TYPE%\*.exe . /Y
copy ..\shaderv\%BUILD_TYPE%\*.pdb . /Y
rem deploy qt program
rem [vcredist(we do not set VCINSTALLDIR)]
%QTDIR%\bin\windeployqt.exe shaderv.exe
cd ..\..
