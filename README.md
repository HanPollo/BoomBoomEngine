# BoomBoomEngine
Game engine for rythm based games.

# Description
A WIP for a game engine to create Rhythm based games.


# Compilation
Once downloaded go to main repo file (BoomBoomEngine folder) and in terminal enter the following commands:
```
git submodule update --init --recursive //This is to get the glfw lib

cd Libraries/glad
mkdir build
cd build
cmake ..
cmake --build . --config Release

cd ../../glfw
mkdir build
cd build
cmake ..
cmake --build . --config Release  

cd ../../..
mkdir build
cd build
cmake ../source
cmake --build .  //Open sln
cd debug
./main.exe

```
