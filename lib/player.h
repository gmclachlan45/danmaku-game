#pragma once

class Player {
private:
    int x;
    int y;

    int score;

public:
    Player();
    ~Player();

    void move_up();
    void move_down();
    void move_left();
    void move_right();
};
