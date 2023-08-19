#pragma once
#include <iostream>
#include "../lib/input_handler.h"

class Game {
private:
	unsigned int state; // State if in menu, in game, game paused etc.
    
    // rendering engine
    // audio engine
    // controller engine
public:
    InputHandler controller;

    Game(void);
    ~Game(void);

};
