:: Awesome build script made by ASM#1010 :))

:: Turn echo off
@echo off
echo Welcome to the epic gaming Nuvola build script
:: Main selection section
:main
echo Please select a choice below
echo 1) Build Nuvola (x64 only)
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
call SetupAndBuild.bat
:: Put everything in an output folder
mkdir Output
copy /y Injector\Release\Injector.exe Output\Injector.exe
copy /y Nuvola\Release\Nuvola.dll Output\Nuvola.dll
goto end

:: Call the injector program
:inject
cd Output
Injector.exe -i Nuvola.dll -n Minecraft.Windows
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
rmdir /s /q "Nuvola\Nuvola.dir"
rmdir /s /q "Nuvola\Release"
rmdir /s /q "Injector\Injector.dir"
rmdir /s /q "Injector\Release"
rmdir /s /q "Injector\obj"
del /q "Injector\*.csproj"
rmdir /s /q "Output"
rmdir /s /q "build"
rmdir /s /q ".vscode"
goto end
:end
echo Task completed! (or failed, I don't know)