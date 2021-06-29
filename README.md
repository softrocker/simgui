# SIMGUI

This library is a wrapper around the [Dear ImGui](https://github.com/ocornut/imgui)   library.
More precisely, this is a modified "SDL + OpenGL-2" example with an API,
which allows C++ programmers to create GUI-based applications from the console ones.

## How to build:
```
mkdir external
cd external
git clone https://github.com/ocornut/imgui.git
git clone https://github.com/libsdl-org/SDL.git
cd ..
git clone https://github.com/softrocker/simgui.git
cd simgui
mkdir build
cd build
cmake ..
```

## Dependencies:
[Dear ImGui](https://github.com/ocornut/imgui)
[SDL](https://github.com/libsdl-org/SDL)