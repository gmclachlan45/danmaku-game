#include "input_handler.h"

InputHandler::InputHandler(void) {
    // use e
    inputType = 1;
}
InputHandler::InputHandler(GLFWwindow* window) {
    pWindow = window;
    inputType = 1;
}

InputHandler::~InputHandler(void) {

}

void InputHandler::handleMenu() {
    // TBD far in future
}

void InputHandler::handleGame(Player* pPlayer) {
    if(glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        std::cout << "Esc ";
    if(glfwGetKey(pWindow, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        std::cout << "Shift ";
    if(glfwGetKey(pWindow, GLFW_KEY_UP) == GLFW_PRESS) {
        std::cout << "Up ";
        pPlayer->moveUp();
    }
    if(glfwGetKey(pWindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
        std::cout << "Down ";
        pPlayer->moveDown();
    }
    if(glfwGetKey(pWindow, GLFW_KEY_LEFT) == GLFW_PRESS) {
        std::cout << "Left ";
        pPlayer->moveLeft();
    }
    if(glfwGetKey(pWindow, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        std::cout << "Right ";
        pPlayer->moveRight();
    }
    if(glfwGetKey(pWindow, GLFW_KEY_Z) == GLFW_PRESS)
        std::cout << "Z ";

	std::cout << std::endl;

    //
}
