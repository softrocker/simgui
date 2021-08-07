# Simgui

This library is a wrapper around the [Dear ImGui](https://github.com/ocornut/imgui)   library.
More precisely, this is a modified "SDL + OpenGL-2" example with an API,
which allows C++ programmers to create GUI-based applications from the console ones.

## How to use:
1. Download libraries that we need (Dear ImGui, SDL and this project):
```
mkdir external
cd external
git clone https://github.com/ocornut/imgui.git
git clone https://github.com/libsdl-org/SDL.git
cd ..
git clone https://github.com/softrocker/simgui.git
```
2. Prepare build configuration for SDL:
```
cd external/SDL
mkdir build
cd build
cmake ..
```
, then build.

3. Build examples 


## Dependencies:
[Dear ImGui](https://github.com/ocornut/imgui)
[SDL](https://github.com/libsdl-org/SDL)