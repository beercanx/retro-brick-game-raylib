# Retro Brick Game - in raylib

## Setup - Windows and JetBrains CLion
* Setup a Toolchain, I went for a MinGW one provided by the manual raylib download....

## Setup - Windows on CLI
* Install CMake and add to path (you can choose User instead of System if you want). 
```
choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
```

* Install MinGW to provide compiler
```
choco install mingw
```

* Other stuff I don't know yet...

## Setup - Ubuntu
* In theory, it should just be...
```
sudo apt install build-essential cmake
```