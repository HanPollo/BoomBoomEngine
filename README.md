# BoomBoomEngine
Game engine for rythm based games.

# Description
A WIP for a game engine to create Rhythm based games.

# Compilation
clone the hito-3 branch to desired folder:
```
git clone --single-branch --branch hito-3 https://github.com/HanPollo/BoomBoomEngine.git
```
Once downloaded open BoomBoomEngine folder with Visual Studio or with a terminal that suports cmake commands

1- Go to BoomBoomEngine folder in terminal (that supports mkdir and cmake commands, preferably Visual Studio's Developer PowerShell as it is done in demo)

2- Write the following code:
```
mkdir build
cd build
cmake ..
cmake --build .  //Or alternatevily Open BoomBoomEngine/build/BoomBoom.sln with Visual Studio and build all solutions
```
This will throw some errors which can be ignored since they are for the next iteration's Audio Engine (not implemented yet).
This will also build all 3rd party Libraries which are used.

Back in terminal make sure you are on BoomBoomEngine/build and run the following code to see demo:
```
cd Examples/Debug
./main.exe
```

You can move the camera freely with WASD keys and mouse to see the models loaded.

