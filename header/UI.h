#include "stdafx.h"



class UI {
private:
    Vector2f position;
    Vector2f size;
public:
    UI();
    UI(Vector2f newPosition);
    UI(Vector2f newPosition, Vector2f newSize);
    UI(View view);
    void setPosition(Vector2f newPosition);
    void setSize(Vector2f newSize);
    void setView(View view);
    Vector2f getPosition();
    Vector2f getSize();
};

