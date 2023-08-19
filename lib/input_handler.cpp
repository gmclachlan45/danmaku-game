#include "input_handler.h"

InputHandler::InputHandler(void) {
    // use enums eventually
    inputType = 1;    
}

InputHandler::~InputHandler(void) {

}

void InputHandler::handleMenu() {
    // TBD far in future
}

void InputHandler::handleGame(GLFWwindow* window, Player* p_player) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        std::cout << "Esc ";
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        std::cout << "Shift ";
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        std::cout << "Up ";
        p_player->move_up();
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        std::cout << "Down ";
        p_player->move_down();
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        std::cout << "Left ";
        p_player->move_left();
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        std::cout << "Right ";
        p_player->move_right();
    }
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        std::cout << "Z ";

	std::cout << std::endl;

    // 
}
