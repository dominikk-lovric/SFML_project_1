#include "../header/UIElement.h"

UIElement::UIElement() {
}

UIElement::UIElement(const Texture &texture, IntRect frame, Vector2f position) {
    initUIElement(texture, frame, position);
}
void UIElement::initUIElement(const Texture &texture, IntRect frame, Vector2f position) {
    sprite = make_shared<Sprite>(texture);
    sprite->setTextureRect(frame);
    sprite->setPosition(position);
    bounds = sprite->getGlobalBounds();
    scaleTo= sprite->getScale();
}

UIElement::UIElement(const Texture &texture, IntRect frame, Vector2f position, Vector2f scale) {
    initUIElement(texture, frame, position,scale);
}
void UIElement::initUIElement(const Texture &texture, IntRect frame, Vector2f position, Vector2f scale) {
    sprite = make_shared<Sprite>(texture);
    sprite->setTextureRect(frame);
    sprite->setPosition(position);
    sprite->setScale(scale);
    bounds = sprite->getGlobalBounds();
    scaleTo= scale;
}


void UIElement::render(RenderWindow& window) {
    window.draw(*sprite);
}

void UIElement::update(RenderWindow& window,View& view) {
    if (sprite->getPosition()!=movePos)moveUpdate();
    if (sprite->getScale()!=scaleTo)scaleUpdate();
}

void UIElement::moveUpdate() {
    if (abs((sprite->getPosition()-movePos).length())<=1)sprite->setPosition(movePos);
    else {
        moveSpeed=moveSpeed*moveLerp;
        Vector2f delta = movePos - sprite->getPosition();
        sprite->move(delta.normalized()*moveSpeed);
    }
}

void UIElement::scaleUpdate() {
    Vector2f delta=scaleTo-sprite->getScale();
    Vector2f size=sprite->getGlobalBounds().size;
    if (abs((delta).length())<0.5)sprite->setScale(scaleTo);
    else {
        scaleSpeed = scaleSpeed*scaleLerp;
        sprite->setScale(sprite->getScale()+delta.normalized()*scaleSpeed);
    }
    size={sprite->getGlobalBounds().size.x-size.x, sprite->getGlobalBounds().size.y-size.y};
    if (delta.length()!=0) {
        if (scaleDir==0||scaleDir==4||scaleDir==8)moveConst({-(size.x/2),0});
        if (scaleDir==2||scaleDir==6||scaleDir==8)moveConst({0,-(size.y/2)});
        if (scaleDir==0||scaleDir==1||scaleDir==7)moveConst({0,-size.y});
        if (scaleDir==5||scaleDir==6||scaleDir==7)moveConst({-size.x,0});
    }
}

void UIElement::scale(Vector2f finalScale, float speed, float lerp, int dir) {
    scaleTo=finalScale;
    scaleSpeed = speed;
    scaleLerp = lerp;
    scaleDir = dir;
}

Vector2f UIElement::getScale() {
    return sprite->getScale();
}



void UIElement::setPosition(Vector2f newPosition) {
    sprite->setPosition(newPosition);
    movePos = sprite->getPosition();
}

void UIElement::setScale(Vector2f newScale) {
    sprite->setScale(newScale);
    scaleTo = sprite->getScale();
}

void UIElement::moveConst(Vector2f delta) {
    sprite->setPosition(getPosition()+ delta);
    movePos = sprite->getPosition();
}

void UIElement::scaleConst(Vector2f delta) {
    sprite->setScale(sprite->getScale()+delta);
    scaleTo = sprite->getScale();
}

void UIElement::move(Vector2f finalPos, float speed, float lerp) {
    if (sprite->getPosition()==movePos) {
        movePos = finalPos;
        moveSpeed = speed;
        moveLerp = lerp;
    }
}

Vector2f UIElement::getPosition() {
    return sprite->getPosition();
}