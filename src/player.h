class player {
private:
    int x;
    int y;

    int score;

public:
    player();
    ~player();

    void move_up();
    void move_down();
    void move_left();
    void move_right();
};
