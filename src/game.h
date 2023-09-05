#pragma once
#include <iostream>
#include <stdexcept>

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


#include "../lib/input_handler.h"
#include "../lib/graphics_renderer.h"

class Game {
private:

	unsigned int state; // State if in menu, in game, game paused etc.
    // Rendering engine
    GraphicsRenderer* renderer;
    // Contraller engine

    // Audio engine

public:
    GLFWwindow* pWindow;
    InputHandler* controller;
    Game(void);
    ~Game(void);
};
