#include "stdafx.h"
#include "UIElement.h"


class Game {
private:
    RenderWindow window;
    VideoMode vm;
    View mainView;
    View UIView;
    bool UI;
    UIElement ue;
    Texture mainTexture;
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


