#include "../header/UI.h"

UI::UI() {
}

UI::UI(Vector2f newPosition, Vector2f newSize) {
    setUI(newPosition,newSize);
}

UI::UI(View view) {
    setUI(view);
}

void UI::setUI(Vector2f newPosition, Vector2f newSize) {
    view.setCenter(newPosition);
    view.setSize(newSize);
}

void UI::setUI(View view) {
    this->view=view;
}

void UI::update(RenderWindow &window) {
    for (int i=0;i<UIElements.size();i++) {
        UIElements[i].update(window,this->view);
    }
}

void UI::render(RenderWindow &window) {
    for (auto &UIElement : UIElements) {
        UIElement.render(window);
    }
}

void UI::setPosition(Vector2f newPosition) {
}

void UI::setSize(Vector2f newSize) {
}

void UI::scaleUIElement(int UIEl, Vector2f newScale, float speed, float lerp, int dir) {
    UIElements[UIEl].scale(newScale,speed,lerp,dir);
}

void UI::setView(View& view) {
    this->view=view;
    this->Position=view.getCenter();
    this->Size=view.getSize();
}

Vector2f UI::getSize() {
    return view.getSize();
}

void UI::addUIElement(UIElement UIElement) {
    UIElements.push_back(UIElement);
}

UIElement UI::getUIElement(int i) {
    if (i>0&&i<UIElements.size()) {
        return UIElements[i];
    }
}

int UI::getUIElementCount() {
    return UIElements.size();
}

View& UI::getView() {
    return view;
}


Vector2f UI::getPosition() {
    return view.getCenter();
}
