# Nuvola
[![Windows](https://svgshare.com/i/ZhY.svg)](https://github.com/DisabledMallis/Nuvola)
[![C++](https://img.shields.io/badge/Made%20with-C++-1f425f.svg)](https://github.com/DisabledMallis/Nuvola)
[![GitHub Downloads](https://img.shields.io/github/downloads/DisabledMallis/Nuvola/total.svg)](https://github.com/DisabledMallis/Nuvola/releases/)
[![GitHub Issues](https://img.shields.io/github/issues/DisabledMallis/Nuvola.svg)](https://github.com/DisabledMallis/Nuvola/issues/)
[![GitHub Issues Closed](https://img.shields.io/github/issues-closed/DisabledMallis/Nuvola.svg)](https://github.com/DisabledMallis/Nuvola/issues/)
[![GitHub Pull-Requests](https://img.shields.io/github/issues-pr/DisabledMallis/Nuvola.svg)](https://github.com/DisabledMallis/Nuvola/pull/)

[![GitHub Forks](https://img.shields.io/github/forks/DisabledMallis/Nuvola.svg?style=social&label=Fork&maxAge=2592000)](https://github.com/DisabledMallis/Nuvola/)
[![GitHub Stars](https://img.shields.io/github/stars/DisabledMallis/Nuvola.svg?style=social&label=Star&maxAge=2592000)](https://github.com/DisabledMallis/Nuvola/)
[![GitHub Watchers](https://img.shields.io/github/watchers/DisabledMallis/Nuvola.svg?style=social&label=Watch&maxAge=2592000)](https://github.com/DisabledMallis/Nuvola)
[![GitHub Contributors](https://img.shields.io/github/contributors/DisabledMallis/Nuvola.svg?style=social&label=Contributors)](https://gitHub.com/DisabledMallis/Nuvola)

Nuvola (previously known as Lunity) is a Minecraft: Windows 10 Edition anticheat penetration testing and toolkit framework

[Discord](https://go-kys.lol/)

# Contributors
These are the contributors since the start of the rewrite.
## Main contributor(s)
[DisabledMallis](https://github.com/DisabledMallis) 
- Main project structure
- Patch system & most patches
- Module system
- Command system
- Bridge/SDK sources & source generator
- ClassBuilder

## Other contributors
[charliecronin3](https://github.com/charliecronin3)
- [Code for LoopbackPacketSender](https://github.com/DisabledMallis/Nuvola/pull/24)

[BoredSathvik](https://github.com/BoredSathvik)
- [Updating injector to a functioning state](https://github.com/DisabledMallis/Nuvola/pull/30)

## Other thanks
[stevemk14ebr](https://github.com/stevemk14ebr)
- [PolyHook2](https://github.com/stevemk14ebr/PolyHook_2_0)

# Building (Windows x64)
Nuvola is a modification for Minecraft: Windows 10 Edition, which, as shown in the name, runs on Windows 10. Nearly every single developer of this (and other) related projects use a 64-bit computer. As such, 32-bit support has been dropped. The target build of Minecraft was likely built using MSVC in Release configuration, and so its best practice to build Nuvola the same way.

## Cloning
You are required to **clone** the repository in some capacity in order for this project to build, so its important to have `git` installed. This project uses many submodules as well, so the zipped source won't provide much help alone.

## Requirements
There are many things needed to properly build Nuvola.

1. Git - Its required to clone & update submodules
2. CMake - CMake is used to generate the files for MSVC to build the project
3. Visual Studio - Visual Studio provides the compilers we need.
    - C++ Desktop development
    - .NET framework development

## Building
A collection of build scripts are provided, this is to simplify the process of compiling the project in its entirety. These scripts are capable of automatically updating the Git submodules and automating other tedious tasks.

To use the scripts, simply run ``.\Nuvola`` in powershell, or run ``Nuvola.bat`` in a command prompt terminal.

# Approvals

Brampedgex, a developer of the Chronos client approves of Nuvola's source code.

![Brampedgex chronos guy](https://media.discordapp.net/attachments/888444667476213791/888560090939015188/unknown.png)