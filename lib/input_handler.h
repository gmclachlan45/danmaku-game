#pragma once

#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "player.h"


class InputHandler {
private:
    // query for controller
    unsigned int inputType;
    GLFWwindow* pWindow;

public:
    // Load the user config
    InputHandler(void);
    InputHandler(GLFWwindow*);
    // InputHandler(unsigned int* pButtonArray, int arraySize);
    ~InputHandler(void);
    void handleMenu(/*Menu* pMenu*/);
    void handleGame(Player*);
};
