#include "game.h"


GLFWwindow* Game::createGameWindow( int xResolution, int yResolution, bool fullscreen ) {
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

    GLFWwindow* pWindow;
    pWindow = glfwCreateWindow(xResolution, yResolution, "Danmaku Game", NULL, NULL);
    if (!pWindow) {
	    std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        throw std::exception();
    }
    
    return pWindow;
}

Game::Game(void) {
    std::cout << "This is the start of a brand new game" << std::endl;
    // Read data from game.data, get screen options
    // TODO: prompt for fullscreen or windowed depending on config
    // Default to 4:3 HD. TODO: add strips for fullscreen
    window = Game::createGameWindow(1024, 768, false);
	/* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
	  std::cout << "Failed to initialize GLAD" << std::endl;
      throw std::exception();

	};

    state = 1; // set the game state to menu
    // load the menus, icons and text

    // Create the controller
}

Game::~Game(void) {
    // save total playtime and resave any other information
    std::cout << "Thanks for playing. Saving a lot of data..." << std::endl;
    // once everything is done, finish and close
    state = 0;
}

