#pragma once

class Player {
public://private:
    int x;
    int y;

    int score;

    //public:
    Player();
    ~Player();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};
