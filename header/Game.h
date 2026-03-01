#include "../header/stdafx.h"



class Game {
private:
    RenderWindow window;
    VideoMode vm;

public:
    Game();
    ~Game();
    void initWindow();
    RenderWindow getWindow();
    void update(Time dt);
    void render();
    bool isOpen();
};


