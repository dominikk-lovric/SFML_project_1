#include "stdafx.h"
class UIElement {
private:
    Texture texture;
    FloatRect bounds;
    shared_ptr<Sprite> sprite;
    Vector2f movePos;
    float moveSpeed;
    float moveLerp;
    Vector2f scaleTo;
    float scaleSpeed;
    float scaleLerp;
    int scaleDir;
public:
    UIElement();
    UIElement(const Texture& texture, IntRect frame, Vector2f position);
    UIElement(const Texture& texture, IntRect frame, Vector2f position, Vector2f scale);
    void initUIElement(const Texture& texture, IntRect frame, Vector2f position, Vector2f scale);
    void initUIElement(const Texture& texture, IntRect frame, Vector2f position);
    void render(RenderWindow& window);
    void update(RenderWindow& window,View& view);
    void moveUpdate();
    void scaleUpdate();
    void updateHover(RenderWindow& window, View& view);
    void setPosition(Vector2f newPosition);
    void setScale(Vector2f newScale);
    void moveConst(Vector2f delta);
    void scaleConst(Vector2f delta);
    void move(Vector2f finalPos, float speed, float lerp);
    void scale(Vector2f finalScale, float speed, float lerp, int dir);
    Vector2f getPosition();
    Vector2f getScale();
};
