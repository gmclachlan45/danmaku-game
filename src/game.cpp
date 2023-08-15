#include "game.h"

game::game() {
    std::cout << "This is the start of a brand new game" << std::endl;

    //load the config and data that determines certain settings

    state = 1; // set the game state to menu
    // load the menus, icons and text

    // Create the controller
}

game::~game() {
    // save total playtime and resave any other information

    //once everything is done finish and close
    state = 0;
}
