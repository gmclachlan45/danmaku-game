#include "player.h"
#include <iostream>
Player::Player( void ) {
    score = 0;
    x = 0;
    y = -200;
}

Player::~Player( void ) {
    // When the game is done, the player's stats are either reworded or thrown out
    std::cout<< "Thanks for playing. Your score was " << score <<std::endl;
}

void Player::moveUp() {
    if(y < 400)
        y++;
    else
        y = 400;
    score++;
}
void Player::moveDown() {
    if(y > -400)
        y--;
    else
        y = -400;
}
void Player::moveLeft() {
    if(x > -300)
        x--;
    else
        x = -300;
}
void Player::moveRight() {
    if(x < 300)
        x++;
    else
        x = 300;
}
