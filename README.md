# Retro Brick Game - in raylib

This is an attempt at recoding another project written in C# and Unity into C++ and Raylib.

The original game can be found here:
* https://github.com/beercan1989/retro-brick-game
* https://beercan.itch.io/retro-brick-game

## Platforms
Supported:
* Windows 10
* Linux

Probable future support:
* Web
* Android

Unlikely future support:
* iOS
* MacOS

## Setup

### MinGW in Windows with Clion bundle

This is for building in Windows to be able to run on Windows.

1) Create the Windows based toolchain based on the bundled MinGW in CLion.
2) Create a CMake profile based on the toolchain.
3) Build, run and debug as normal.

### MinGW in Windows CLI

Basically this is the normal build in Windows to be able to run on Windows type thing.

1) Install MinGW natively on Windows, I use https://community.chocolatey.org
```powershell
choco install mingw
```

2) Create a toolchain using MinGW and set the environment to the location of mingw and let it do its detection magic, for me mingw got installed under:
```
C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64
```

3) Create a CMake profile that uses the MinGW Windows toolchain.

4) Build, run and debug as normal now.

### MinGW in WSL

Basically this is build in Linux (Ubuntu) to be able to run on Windows.

1) Install MinGW in the WSL environment.
```bash
sudo apt install cmake mingw-w64 gdb-mingw-w64 
```

2) Manually create the toolchain instead of relying on the cmake auto-detection.
```
CMake:        /usr/bin/cmake
Make:         /usr/bin/make
C Compiler:   /usr/bin/x86_64-w64-mingw32-gcc
C++ Compiler: /usr/bin/x86_64-w64-mingw32-g++
Debugger:     /usr/bin/x86_64-w64-mingw32-gdb
```

3) Create a CMake profile that uses the WSL MinGW tool chain and in the CMake options field add:
```
-DCMAKE_TOOLCHAIN_FILE=CMake/x86_64-w64-mingw32.cmake
```

4) Build, run and debug as normal now.

### Linux in WSL

Basically this is to build in Linux (Ubuntu) to be able to run on Linux.

1) Install some stuff for building
```bash
sudo apt install cmake build-essential gdb-multiarch
```

2) Install some stuff for Raylib dependencies
```bash
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```

3) Create a toolchain using WSL and let the default defection to work as it should pick up the Linux GNU commands.

4) Create another CMake profile that uses the Linux WSL toolchain.

5) Update the run configuration for the GUI app you want to build and run from WSL to include the DISPLAY value for your machine. I could get away with setting `DISPLAY=%HOSTNAME%.mshome.net:0`, but basically it's the same value as laid out in [xlaunch/README.md](xlaunch/README.md).

6) Build, run and debug as normal now.