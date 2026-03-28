#include "stdafx.h"
#include "UI.h"
#include "grid.h"
#include "apple.h"

class Game {
private:
    RenderWindow window;
    VideoMode vm;
    View mainView;
    View UIView;
    View GameOverView;
    bool UIb;
    UI ui;

    Texture blueTexture;
    Texture redTexture;
    Texture snakeTexture;
    Texture appleTexture;
    int i;
    snake snake;
    apple apple;
    grid grid;
    bool gameRunning;
public:
    Game();
    ~Game();
    void initWindow();
    void initSnake();
    RenderWindow& getWindow();
    void update(Time dt);
    void render();
    bool isOpen();
    void pollEvents();
};


