//
// Created by domin on 3/2/2026.
//

#include "../header/UI.h"

UI::UI() {
}

UI::UI(Vector2f newPosition) {
    position = newPosition;
}

UI::UI(Vector2f newPosition, Vector2f newSize) {
    position = newPosition;
    size = newSize;
}

UI::UI(View view) {
    position=view.getCenter()-view.getSize()/2.f;
    size = view.getSize();
}

void UI::setPosition(Vector2f newPosition) {
    position = newPosition;
}

void UI::setSize(Vector2f newSize) {
    size = newSize;
}

void UI::setView(View view) {
    position=view.getCenter()-view.getSize()/2.f;
    size = view.getSize();
}

Vector2f UI::getSize() {
    return size;
}

Vector2f UI::getPosition() {
    return position;
}
