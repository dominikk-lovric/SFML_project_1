//
// Created by domin on 2026-03-27.
//

#include "../header/grid.h"

grid::grid() {
}

grid::grid(View &view,int x, int y) {
    initGrid(view, x, y);
}

grid::grid(View &view,int x, int y, Color bg, Color fg, int lt) {
    initGrid(view, x, y, bg, fg, lt);
}

void grid::initGrid(View &view,int x, int y) {
    this->x=x;
    this->y=y;
    bg=Color(150,150,150, 100);
    fg=Color(100,100,100);
    lt=2;
    this->view=view;
}

void grid::initGrid(View &view,int x, int y, Color bg, Color fg, int lt) {
    this->x=x;
    this->y=y;
    this->bg=bg;
    this->fg=fg;
    this->lt=lt;
    this->view=view;
}

void grid::setBg(Color bg) {
    this->bg=bg;
}

void grid::setFg(Color fg) {
    this->fg=fg;
}

void grid::setLt(int lt) {
    this->lt=lt;
}

void grid::render(RenderWindow &window) {
    RectangleShape shape;
    shape.setSize({view.getSize().x/x,view.getSize().y/y});
    shape.setOutlineColor(fg);
    shape.setOutlineThickness(lt);
    shape.setFillColor(bg);
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            shape.setPosition(Vector2f(i*shape.getSize().x, j*shape.getSize().y)+view.getCenter()-view.getSize()/2.f);
            window.draw(shape);
        }
    }
}

Vector2i grid::getSize() {
    return Vector2i(x,y);
}

Vector2f grid::getCellSize() {
    return {view.getSize().x/x,view.getSize().y/y};
}


