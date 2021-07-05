@echo off
echo Welcome to the epic gaming Lunity build script
:main
echo Please select a choice below
echo 1) Build Lunity (x64 only)
echo 2) Inject
echo 3) Clean project
set choice=
set /p choice=Make a selection:
if not '%choice%'=='' set choice=%choice:~0,1%
if '%choice%' == '1' goto build
if '%choice%' == '2' goto inject
if '%choice%' == '3' goto clean
echo "%choice%" is not valid, try again...
goto main
:build
git submodule update --init --recursive
cd Lunity
cd Lib
cd PolyHook_2_0
cmake -B"./_build" -DCMAKE_INSTALL_PREFIX="./_install/" -DPOLYHOOK_BUILD_SHARED_LIB=OFF
cmake --build "./_build" --config Release --target INSTALL
cd ..
cd ..
cd ..
cmake .
cmake --build . --config Release
goto end
:inject
cd Injector
cd Native
cd Release
Injector.exe -i Lunity.dll
cd ..
cd ..
cd ..
goto end
:clean
rmdir /s /q "CMakeFiles"
rmdir /s /q "x64"
del /q /s "*.vcxproj"
del /q /s "*.vcxproj.*"
del /q "*.sln"
del /q /s "cmake_install.cmake"
del /q /s "CMakeCache.txt"
FOR /d /r . %%d IN (CMakeFiles) DO @IF EXIST "%%d" rd /s /q "%%d"
rmdir /s /q "Lunity\Lunity.dir"
rmdir /s /q "Lunity\Release"
rmdir /s /q "Injector\Native\Injector.dir"
rmdir /s /q "Injector\Native\Release"
goto end
:end
echo Task completed! (or failed, I don't know)