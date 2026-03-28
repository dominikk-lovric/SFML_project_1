#include "stdafx.h"
#include "snake.h"
class apple {
private:
    Vector2i position;
    Vector2i gridSize;
    Texture texture;
    Vector2f scale;
    IntRect frame;
    View view;
    int frameCount;
    Clock anim;
public:
    apple();
    apple(Texture &texture, Vector2i frame, Vector2i gridSize, Vector2f scale, View view);
    void initApple(Texture &texture, Vector2i frame, Vector2i gridSize, Vector2f scale, View view);
    void update(snake &snake);
    void render(RenderWindow &window);
    void setPosition(Vector2i newPos);
};

