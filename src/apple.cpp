#include "../header/apple.h"

apple::apple() {
}

apple::apple(Texture &texture, Vector2i frame, Vector2i gridSize,  Vector2f scale, View view) {
    initApple(texture, frame, gridSize, scale, view);
}

void apple::initApple(Texture &texture, Vector2i frame, Vector2i gridSize, Vector2f scale, View view) {
    this->texture = texture;
    this->gridSize = gridSize;
    this->frame.position=Vector2i(0,0);
    this->frame.size = frame;
    frameCount=texture.getSize().x/this->frame.size.x;
    position={-1,-1};
    this->scale = scale;
    srand(time(NULL));
    this->view = view;
    anim.restart();
}

void apple::update(snake &snake) {
    if (position.x<0&&position.y<0) {
        bool flag = false;
        while (!flag) {
            position.x=rand()%gridSize.x;
            position.y=rand()%gridSize.y;
            if (!snake.isElementAtPosition(position)) {flag=true;}
        }
    }else {
        if (snake.getHeadPos().x==position.x&&snake.getHeadPos().y==position.y) {
            position={-1,-1};
            snake.addBody();
        }
    }
}

void apple::render(RenderWindow &window) {
    if (anim.getElapsedTime().asSeconds()>0.25) {
        frame.position.x+=frame.size.x;
        if (frame.position.x>=frame.size.x*frameCount) frame.position.x=0;
        anim.restart();
    }
    Sprite apple = Sprite(texture);
    apple.setTextureRect(frame);
    apple.setScale({scale.x/apple.getGlobalBounds().size.x, scale.y/apple.getGlobalBounds().size.y});
    apple.setPosition(Vector2f(position.x*view.getSize().x/gridSize.x,position.y*view.getSize().y/gridSize.y)+view.getCenter()-view.getSize()/2.f);
    window.draw(apple);
}

void apple::setPosition(Vector2i newPos) {
    position.x=newPos.x;
    position.y=newPos.y;
}
