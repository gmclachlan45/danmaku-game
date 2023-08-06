#include "player.h"
#include <iostream>
player::player( void ) {

}

player::~player( void ) {
    // When the game is done, the player's stats are either reworded or thrown out
    std::cout<< "Thanks for playing. Your score was " << score <<std::endl;
}
void player::move_up() {
    y++;
    score++;
}
void player::move_down() {
    y--;
}
void player::move_left() {
    x--;
}
void player::move_right() {
    x++;
}
