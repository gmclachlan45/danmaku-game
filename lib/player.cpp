#include "player.h"
#include <iostream>
Player::Player( void ) {

}

Player::~Player( void ) {
    // When the game is done, the player's stats are either reworded or thrown out
    std::cout<< "Thanks for playing. Your score was " << score <<std::endl;
}
// TODO: Update funct names
void Player::move_up() {
    y++;
    score++;
}
void Player::move_down() {
    y--;
}
void Player::move_left() {
    x--;
}
void Player::move_right() {
    x++;
}
