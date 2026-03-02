#include "stdafx.h"
class UIElement {
private:
    Texture texture;
    Vector2f scale;
    Vector2f position;
    FloatRect bounds;
    shared_ptr<Sprite> sprite;
    public:
    UIElement();
    UIElement(const Texture& texture, Vector2f position);
    UIElement(const Texture& texture, Vector2f position, Vector2f scale);
    void initUIElement(const Texture& texture, Vector2f position, Vector2f scale);
    void initUIElement(const Texture& texture, Vector2f position);
    void render(RenderWindow& window);
    void update();
    void setPosition(Vector2f newPosition);
    void setScale(Vector2f newScale);
    void move(Vector2f delta);
};
