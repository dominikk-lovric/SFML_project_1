#include <iostream>
#include "stdafx.h"

class snake {
private:
    int direction;
    int x;
    int y;
    Texture tex;
    IntRect head;
    IntRect body;
    IntRect tail;
    IntRect turn;
    Vector2i headPos;
    vector<Vector2i> bodyPos;
    Vector2i tailPos;
    Vector2f scale;
    Vector2f start;
    Vector2f cell;
    Clock clock;
    bool bodyAdd;
    float time;
    int cpd;
public:
    snake();
    snake(const Texture &texture, Vector2i Size, Vector2i dim, View &view);
    void initSnake(const Texture &texture, Vector2i Size, Vector2i dim, View &view);
    void update(Time dt);
    void updatePos(int i, Vector2i newPos);
    void render(RenderWindow &window);
    void addBody();
    Vector2i getHeadPos();
    bool isElementAtPosition(Vector2i pos);
    bool isElementInBody(Vector2i pos);
};
