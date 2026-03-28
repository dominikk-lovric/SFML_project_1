#include "../header/snake.h"

snake::snake() {
}

snake::snake(const Texture &texture, Vector2i Size, Vector2i dim, View &view) {
    initSnake(texture, Size, dim, view);
}


void snake::initSnake(const Texture &texture, Vector2i Size, Vector2i dim, View &view) {
    tex=texture;
    x=dim.x;
    y=dim.y;
    direction=1;
    cpd=1;
    head=IntRect({0,0},Size);
    body=IntRect({Size.x,0},Size);
    tail=IntRect({2*Size.x,0},Size);
    turn=IntRect({3*Size.x,0},Size);
    headPos={2,0};
    while (bodyPos.size()>0) bodyPos.pop_back();
    bodyPos.push_back({1,0});
    tailPos={0,0};
    scale={view.getSize().x/x/Size.x, view.getSize().y/y/Size.y};
    start=view.getCenter()-view.getSize()/2.f;
    cell=Vector2f(view.getSize().x/x,view.getSize().y/y);
    clock.restart();
    bodyAdd=0;
    time=0.2;
}

void snake::update(Time dt) {
    if (Keyboard::isKeyPressed(Keyboard::Key::W)&&(headPos.y!=bodyPos[0].y+1))cpd=0;
    else if (Keyboard::isKeyPressed(Keyboard::Key::A)&&(headPos.x!=bodyPos[0].x+1))cpd=3;
    else if (Keyboard::isKeyPressed(Keyboard::Key::S)&&(headPos.y!=bodyPos[0].y-1))cpd=2;
    else if (Keyboard::isKeyPressed(Keyboard::Key::D)&&(headPos.x!=bodyPos[0].x-1))cpd=1;
    if (clock.getElapsedTime().asSeconds()>=time) {
        clock.restart();
        if (!bodyAdd)tailPos=bodyPos[bodyPos.size()-1];
        else bodyAdd=0;
        updatePos(0, headPos);
        direction=cpd;
        if (direction==0) headPos.y--;
        else if (direction==1) headPos.x++;
        else if (direction==2) headPos.y++;
        else if (direction==3) headPos.x--;
    }

}

void snake::updatePos(int i, Vector2i newPos) {
    if (i<bodyPos.size()-1)updatePos(i+1, bodyPos[i]);
    if (i!=0)bodyPos[i]=bodyPos[i-1];
    else{bodyPos[i]=headPos;}
}

void snake::render(RenderWindow &window) {
    Sprite sprite = Sprite(tex);
    sprite.setScale(scale);
    sprite.setTextureRect(head);
    sprite.setOrigin(sprite.getLocalBounds().size/2.f);
    sprite.setPosition(Vector2f(cell.x*headPos.x,cell.y*headPos.y)+start+sprite.getGlobalBounds().size/2.f);

    if (headPos.x-bodyPos[0].x==0) {
        if (headPos.y-bodyPos[0].y>0)sprite.setRotation(degrees(90));
            else sprite.setRotation(degrees(-90));
    }else if (headPos.y-bodyPos[0].y==0) {
        if (headPos.x-bodyPos[0].x>0)sprite.setRotation(degrees(0));
        else sprite.setRotation(degrees(180));
    }
    window.draw(sprite);
    for (int i=0;i<bodyPos.size();i++) {
        Vector2i prevDir={0,0};
        Vector2i nextDir={0,0};
        if (i==0)prevDir=Vector2i(-bodyPos[0].x+headPos.x,-bodyPos[0].y+headPos.y);
        else prevDir=Vector2i(-bodyPos[i].x+bodyPos[i-1].x,  -bodyPos[i].y+bodyPos[i-1].y);
        if (i==bodyPos.size()-1)nextDir=Vector2i(-bodyPos[i].x+tailPos.x, -bodyPos[i].y+tailPos.y);
        else nextDir=Vector2i(-bodyPos[i].x+bodyPos[i+1].x,  -bodyPos[i].y+bodyPos[i+1].y);
        sprite.setPosition(Vector2f(cell.x*bodyPos[i].x,cell.y*bodyPos[i].y)+start+sprite.getGlobalBounds().size/2.f);
        if ((prevDir.x==0&&nextDir.x==0) || (prevDir.y==0&&nextDir.y==0)) {
            sprite.setTextureRect(body);
            if (prevDir.x!=0) sprite.setRotation(degrees(prevDir.x*90+90));
            if (prevDir.y!=0) sprite.setRotation(degrees(prevDir.y*90));
        }else {
            sprite.setTextureRect(turn);
            if (prevDir.x==1) {
                sprite.setRotation(degrees(-45+(nextDir.y*45)));
            }else if (prevDir.x==-1) {
                sprite.setRotation(degrees(135-(nextDir.y*45)));
            }else if (prevDir.x==0) {
                if (prevDir.y==1) {
                sprite.setRotation(degrees(45-(nextDir.x*45)));
                }else if (prevDir.y==-1) {
                sprite.setRotation(degrees(45-(nextDir.x*135)));
                }
            }
        }
        window.draw(sprite);
    }
    sprite.setTextureRect(tail);
    sprite.setPosition(Vector2f(cell.x*tailPos.x,cell.y*tailPos.y)+start+sprite.getGlobalBounds().size/2.f);
    if (bodyPos[bodyPos.size()-1].x-tailPos.x==0) {
        if (bodyPos[bodyPos.size()-1].y-tailPos.y>0) {
            sprite.setRotation(degrees(90));
        }else{
            sprite.setRotation(degrees(-90));
        }
    }
    else if (bodyPos[bodyPos.size()-1].y-tailPos.y==0) {
        if (bodyPos[bodyPos.size()-1].x-tailPos.x>0) {
            sprite.setRotation(degrees(0));
        }else {
            sprite.setRotation(degrees(180));
        }
    }
    window.draw(sprite);
}

void snake::addBody() {
    bodyPos.push_back(bodyPos[bodyPos.size()-1]);
    bodyAdd=1;
}

Vector2i snake::getHeadPos() {
    return headPos;
}

bool snake::isElementAtPosition(Vector2i pos) {
    bool flag=false;
    if (headPos.x==pos.x && headPos.y==pos.y) flag=true;
    for (int i=0;i<bodyPos.size();i++) {
        if (bodyPos[i].x==pos.x && bodyPos[i].y==pos.y) flag=true;
    }
    if (tailPos.x==pos.x && tailPos.y==pos.y) flag=true;
    return flag;
}

bool snake::isElementInBody(Vector2i pos) {
    bool flag=false;
    for (int i=0;i<bodyPos.size();i++) {
        if (bodyPos[i].x==pos.x && bodyPos[i].y==pos.y) flag=true;
    }
    if (tailPos.x==pos.x && tailPos.y==pos.y) flag=true;
    return flag;
}


