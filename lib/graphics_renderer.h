#pragma once
#include <iostream>
#include <stdexcept>

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


class GraphicsRenderer {
    // private:
    GLFWwindow* pWindow;
    int xResolution;
    int yResolution;
    void initializeWindow();
    void initializeGL();
    //

 public:
    GraphicsRenderer( void );
    ~GraphicsRenderer( void );
    GLFWwindow* getWindow();
    // Render
};
