:: Update submodules
echo Updating git stuff
call GitUpdate.bat
:: Setup classbuilder to generate the bridge source code
echo Generating sources
call GenSources.bat
:: Build submodules
echo Building submodules
call BuildModules.bat
:: Build all of Nuvola (Injector, Client, Etc)
echo Building Nuvola
call Build.bat