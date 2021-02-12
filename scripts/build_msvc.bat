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

:_tag_build_trace_nodes
rem ===== build trace <3rd: nodeeditor> =====

mkdir build\nodes
cd build\nodes
cmake -G "%BUILD_COMPILE%" %BUILD_ARCH_ARG% -DBUILD_TESTING=OFF ^
-DCMAKE_INSTALL_PREFIX=%~dp0..\build\dependency\nodes ^
../../nodes/nodeeditor-2.1.3
cmake --build . --config %BUILD_TYPE% -j 8
cmake --install . --config %BUILD_TYPE%
cd ..\..

:_tag_build_trace_shaderv
rem ===== build trace <shaderv> =====

mkdir build\shaderv
cd build\shaderv
cd ..\..

:_tag_archive
rem ===== archive trace =====

mkdir build\archive
cd build\archive
%QTDIR%\bin\windeployqt.exe
cd ..\..
