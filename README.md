# BoomBoomEngine
Game engine for rythm based games.

# Description
A WIP for a game engine to create Rhythm based games.

# Documentation
All the required documentation is on the github Wiki page: https://github.com/HanPollo/BoomBoomEngine/wiki


# Compilation
clone the hito-4 branch to desired folder:
```
git clone https://github.com/HanPollo/BoomBoomEngine.git
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

Back in terminal make sure you are on BoomBoomEngine/build and run the following code to get to engine demo:
```
cd Engine/Debug
./main.exe
```
In the Wiki you can find documentation and how to use indications.
