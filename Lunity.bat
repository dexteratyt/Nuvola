@echo off
echo Welcome to the epic gaming Lunity build script
:main
echo Please select a choice below
echo 1) Build Lunity (x64 only)
echo 2) Clean project
set choice=
set /p choice=Make a selection:
if not '%choice%'=='' set choice=%choice:~0,1%
if '%choice%' == '1' goto build
if '%choice%' == '2' goto clean
echo "%choice%" is not valid, try again...
goto main
:build
cmake .
cmake --build . --config Release
goto end
:clean
rmdir /s /q CMakeFiles
rmdir /s /q Lunity/CMakeFiles
:end