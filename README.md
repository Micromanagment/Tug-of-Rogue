# Tug-of-Rogue (C++ / ncurses)
A multiplayer Tug of War style game with time travel mechanics, built in C++ with ncurses for rendering and premake for build automation.
Currently a work in progress

# Current Progress
- [x] Set up Premake build
- [ ] Set up Premake build for Windows
- [ ] Add Logging
- [ ] Add Event System
- [ ] Add Layers
- [ ] Add Controls
- [ ] Add Units
- [ ] Add Map Movement
- [ ] Add Multiplayer

## How to build the game (Linux)
### gmake option
- open a terminal into the repository
- run generate.sh
- make
- run with Run.sh
## How to build the game (Windows)
### Create a .bat file or run
- run generate.bat

##
## How to run tests on Linux
1. Clone repository, open terminal of choice in downloaded repository
2. Run this commands:
 - ./vendor/premake/premake5 gmake
 - make - This creates the actual executable
 
 ##
## How to run tests on Windows
1. Clone repository, open cmd in downloaded repository
2. Run this commands:
 - call vendor\bin\premake\premake5.exe vs2017
 
## Project Structure:

### App/

    src # Game

### Core/
    
    src  # Engine
    
    
