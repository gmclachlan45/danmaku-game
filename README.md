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
  - `choco install mingw` Installs all the GNU tools
  - `choco install cmake --installargs 'ADD_CMAKE_TO_PATH=User'`
- On Linux
- OpenBSD uses Clang by default, so the GNU tools will need to be installed separately
  - `doas pkg_add git g++ cmake gmake`
  - to use GNU's C++ compiler, you'll have to use `eg++`
  - Likewise, to use GNU make, use `gmake`
- FreeBSD verification for this is coming soon

## External Libs
These are the libraries being used in this project.
For now, you must build/download their headers and binaries
and add them to include and lib files located at `[PROJECT ROOT]/../external`.
The following libraries are required:
- glfw3
  - To build from source:
    - `cd ../external/`
    - `git clone https://github.com/glfw/glfw.git`
    - `cd glfw`
    - `cmake -S . -B build`
    - `cd build`
    - run the appropriate `make` command
  - Move `glfw/include/GLFW/` into `../external/include/` and move `glfw/build/src/libglfw3.a` into `../external/lib/`
- glad
  - This is provided by an online generator at https://glad.dav1d.de/
    - Set Language to `C/C++` 
    - Under API set gl to `Version 3.3`
    - Under Specification, choose `OpenGL` 
    - Under Profile choose `Core`
    - Click Generate
  - Download the glad.zip, unzip it
  - Move `glad/include/KHR/` and `glad/include/glad/` into `../external/include/`
- glm
  - As a header only library, you only clone the header into `../external/include/`
    - `cd ../external/`
    - `git clone https://github.com/g-truc/glm.git`
  - then move `glm/glm/` into `../external/include/`
  
- TBD resources library
- TBD audio library

# Build instructions
## Windows
1.) In the root of this project, run `cmake . -G "MinGW Makefiles"`
2.) Run `mingw32-make`

## Linux
1.) In the root of this project, run `cmake .`
2.) Run `make`

## *BSD
1.) In the root of this project, run `cmake -G "Unix Makefiles" -D CMAKE_C_COMPILER=egcc -D CMAKE_CXX_COMPILER=eg++ .`
2.) Run `gmake` 
