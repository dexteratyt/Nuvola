:: Awesome build script made by ASM#1010 :))

:: Turn echo off
@echo off
echo Welcome to the epic gaming Lunity build script
:: Main selection section
:main
echo Please select a choice below
echo 1) Build Lunity (x64 only)
echo 2) Inject
echo 3) Clean project
:: Reset the choice var
set choice=
:: Get input for choice var
set /p choice=Make a selection:
if not '%choice%'=='' set choice=%choice:~0,1%
:: Jump to respective code
if '%choice%' == '1' goto build
if '%choice%' == '2' goto inject
if '%choice%' == '3' goto clean
:: Invalid choice, send them back to try again
echo "%choice%" is not valid, try again...
goto main

:: Build section, actually build the project and output the generated files
:build
:: Update submodules
git submodule update --init --recursive
cd Lunity
cd Lib
cd PolyHook_2_0
:: Build polyhook
cmake -B"./_build" -DCMAKE_INSTALL_PREFIX="./_install/" -DPOLYHOOK_BUILD_SHARED_LIB=OFF
cmake --build "./_build" --config Release --target INSTALL
cd ..
cd ..
cd ..
:: Build all of Lunity (Injector, Client, Etc)
cmake .
cmake --build . --config Release
:: Put everything in an output folder
mkdir Output
copy /y Injector\Managed\Release\Injector.exe Output\Injector.exe
copy /y Lunity\Release\Lunity.dll Output\Lunity.dll
goto end

:: Call the injector program
:inject
cd Output
Injector.exe -i Lunity.dll -n Minecraft.Windows
cd ..
goto end

:: Clean-up files generated with CMake
:clean
rmdir /s /q "CMakeFiles"
rmdir /s /q "x64"
del /q /s "*.vcxproj"
del /q /s "*.vcxproj.*"
del /q "*.sln"
del /q "*.csproj"
del /q /s "cmake_install.cmake"
del /q /s "CMakeCache.txt"
FOR /d /r . %%d IN (CMakeFiles) DO @IF EXIST "%%d" rd /s /q "%%d"
rmdir /s /q "Lunity\Lunity.dir"
rmdir /s /q "Lunity\Release"
rmdir /s /q "Injector\Managed\Injector.dir"
rmdir /s /q "Injector\Managed\Release"
rmdir /s /q "Injector\Managed\obj"
del /q "Injector\Managed\*.csproj"
rmdir /s /q "Output"
rmdir /s /q "build"
goto end
:end
echo Task completed! (or failed, I don't know)