# BoomBoomEngine
Game engine for rythm based games.

# Description
A WIP for a game engine to create Rhythm based games.

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
cd Examples/Debug
./main.exe
```
Create notes where the cursor is with space and save the song with Q.
Then you can reload the song and continue editing with loadSong.exe which is in the same directory as main.exe.
You can also play the song in playSong.exe in the same directory.
