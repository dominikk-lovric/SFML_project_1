#include "stdafx.h"
#include "UIElement.h"

class UI {
private:
    vector<UIElement> UIElements;
    View view;
    Vector2f Position;
    Vector2f Size;
public:
    UI();
    UI(Vector2f newPosition, Vector2f newSize);
    UI(View view);
    void setUI(Vector2f newPosition, Vector2f newSize);
    void setUI(View view);
    void update(RenderWindow& window);
    void render(RenderWindow& window);
    void setPosition(Vector2f newPosition);
    void setSize(Vector2f newSize);
    void setView(View& view);
    Vector2f getPosition();
    Vector2f getSize();
    void addUIElement(UIElement UIElement);
    UIElement getUIElement(int i);
    int getUIElementCount();
    View& getView();
    void scaleUIElement(int UIEl, Vector2f newScale, float speed, float lerp, int dir);
    bool getElementHover(int i, RenderWindow& window);
};

