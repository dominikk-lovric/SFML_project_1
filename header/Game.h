#include "stdafx.h"
#include "UI.h"


class Game {
private:
    RenderWindow window;
    VideoMode vm;
    View mainView;
    View UIView;
    bool UIb;
    UI ui;

    Texture blueTexture;
    Texture redTexture;
    int i;
public:
    Game();
    ~Game();
    void initWindow();
    RenderWindow& getWindow();
    void update(Time dt);
    void render();
    bool isOpen();
    void pollEvents();
};


