# Time Of Prosperity

I'm writing this game because I was bored and I'm trying to kinda write anything. 
It's Civilization based game - turn strategy 4X, however i want to implement some mechanics that are unique and I try to not base on current civ games
mainly, I played civ 3, 5 and 6 

Graphics Library (in future): raylib

What I plan to add in the future

- All well known mechanics that we know from Civilization series such as cities, units, wonders, buildings, workers, technology etc.
- GUI (would be nice, but first game has to work)
- AI


# Run

Currently it's basic project with CMakeLists.txt, first I want to implement basic stuff, then  
I'm using Ninja-build, so my commands look like this

```sh
# To generate ninja-build files in build folder
cmake -S . -B build -G Ninja

# To build
ninja -C build

# To run
build/run
```
