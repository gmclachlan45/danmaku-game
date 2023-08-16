#include "game.h"

Game::Game(void) {
    std::cout << "This is the start of a brand new game" << std::endl;

    //load the config and data that determines certain settings

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
