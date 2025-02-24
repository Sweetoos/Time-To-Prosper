# Time Of Prosperity

I'm writing this game because I was bored and I'm trying to kinda write anything. 
It's Civilization based game - turn strategy 4X, however i want to implement some mechanics that are unique and i try to not base on current civ games
mainly i played civ 3 and 6 (i know that 5 is the best)

What I plan to add in the future

- All well known mechanics that we know from Civilization series such as cities, units, wonders, buildings, workers, technology etc.
- GUI (would be nice, but first game has to work)
- AI


# Run

Currently it's basic project with CMakeLists.txt without any additional libraries to install
I'm using Ninja-build, so my commands look like this

```sh
# To generate ninja-build files in build folder
cmake -S . -B build -G Ninja

# To build
ninja -C build

# To run
build/run
```
