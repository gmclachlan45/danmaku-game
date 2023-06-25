# danmaku-game

A 2D Shmup being made as a collaborative passion project

# Requirements
## Development Tools
These are the following tools being used in this project:
- Git (obviously)
- The Gnu Compiler Collection
- CMake
- Gnu Make
- Doxygen
- CPPUnit

Some notes (for myself):
- On Windows all development tools have been installed using the Chocolatey package manager using the following
  - `choco install git`
  - `choco install mingw`
  - `choco install cmake --installargs 'ADD_CMAKE_TO_PATH=User'`

## External Libs
These are the libraries being used in this project.
For now, you must build/download their headers and binaries
and add them to include and lib files located at `[PROJECT ROOT]/../external`.
The following libraries are required:
- glfw3
  - To build from source:
    - `cd ../external`
    - `git clone https://github.com/glfw/glfw.git`
    - `cd glfw`
    - `cmake -S . -B build`
    - `cd build`
    - `make`
  - Move `glfw/include/GLFW/` into `../external/include/` and move `glfw/build/src/libglfw3.a` into `../external/lib/`
- glad
  - Windows: move `glad/` and `KHR/` into `../external/include/`
- TBD resources library
- TBD audio library

# Build instructions
## Windows
1.) In the root of this project, run `cmake . -G "MinGW Makefiles"`
2.) Run `mingw32-make`

## Linux/*BSD
1.) In the root of this project, run `cmake .`
2.) Run `make`
