#include "game.h"


/*GLFWwindow* Game::createGameWindow( int xResolution, int yResolution, bool fullscreen ) {
}
*/
Game::Game(void) {
    std::cout << "This is the start of a brand new game" << std::endl;
    // Read data from game.data, get screen options
    // TODO: prompt for fullscreen or windowed depending on config
    // Default to 4:3 HD. TODO: add strips for fullscreen
    renderer = new GraphicsRenderer();
    controller = new InputHandler(renderer->getWindow());
    pWindow = renderer->getWindow();
        //createGameWindow(1024, 768, false);

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
