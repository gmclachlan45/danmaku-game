cmake_minimum_required(VERSION 3.20)
project(danmaku-game VERSION 0.1)

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

# set(GCC_COVERAGE_COMPILE_FLAGS "")
if(WIN32)
  set(GCC_COVERAGE_LINK_FLAGS    "-lopengl32 -lgdi32")
endif()


# find_package(Threads)

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

Add_executable(danmaku-game src/glad.c src/main.cpp)

target_include_directories(danmaku-game PRIVATE ${CMAKE_BINARY_DIR}/../external/include)
#if(WIN32)
target_link_libraries(danmaku-game ${CMAKE_BINARY_DIR}/../external/lib/libglfw3.a)
#endif()

# target_link_libraries(danmaku-game
#  Threads::Threads
#  ${CMAKE_DL_LIBS})
