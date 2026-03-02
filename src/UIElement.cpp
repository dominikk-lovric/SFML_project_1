#include "../header/UIElement.h"

UIElement::UIElement() {
}

UIElement::UIElement(const Texture &texture, Vector2f position) {
    initUIElement(texture, position);
}
void UIElement::initUIElement(const Texture &texture, Vector2f position) {
    this->position = position;
    sprite = make_shared<Sprite>(texture);
    sprite->setPosition(position);
    bounds = sprite->getGlobalBounds();
}

UIElement::UIElement(const Texture &texture, Vector2f position, Vector2f scale) {
    initUIElement(texture, position,scale);
}
void UIElement::initUIElement(const Texture &texture, Vector2f position, Vector2f scale) {
    this->position = position;
    sprite = make_shared<Sprite>(texture);
    sprite->setPosition(position);
    sprite->setScale(scale);
    bounds = sprite->getGlobalBounds();
}


void UIElement::render(RenderWindow& window) {
    window.draw(*sprite);
}

void UIElement::update() {
}

void UIElement::setPosition(Vector2f newPosition) {
    position = newPosition;
}

void UIElement::setScale(Vector2f newScale) {
    scale = newScale;
}

void UIElement::move(Vector2f delta) {
    position += delta;
    sprite->setPosition(position);
}
