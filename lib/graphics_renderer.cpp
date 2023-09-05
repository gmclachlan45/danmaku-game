#include "graphics_renderer.h"

void GraphicsRenderer::initializeWindow() {
    // Initialize OpenGL
    if (!glfwInit()){
        std::cout << "OpenGL failed to initialize " << std::endl;
        throw std::exception();
    }

	/* Add hints to specify OpenGL profile */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// TODO start: Create rendering engine to handle the drawing of objects and menus
    /* Create a windowed mode window and its OpenGL context */

    pWindow = glfwCreateWindow(xResolution, yResolution, "Danmaku Game", NULL, NULL);
    if (!pWindow) {
	    std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        throw std::exception();
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);


}
void GraphicsRenderer::initializeGL(){

}

GLFWwindow* GraphicsRenderer::getWindow() {
    return pWindow;
};

GraphicsRenderer::GraphicsRenderer( void ) {
    xResolution = 1024;
    yResolution =768;
    GraphicsRenderer::initializeWindow();
//    GraphicsRenderer::initializeGL
    // initialize shaders

    // Open up load screen while background works
}

GraphicsRenderer::~GraphicsRenderer( void ) {

}
