#include "stdafx.h"


class grid {
    private:
    int x,y;
    Color bg;
    Color fg;
    int lt;
    View view;
public:
    grid();
    grid(View &view,int x,int y);
    grid(View &view,int x,int y,Color bg,Color fg, int lt);
    void initGrid(View &view,int x,int y);
    void initGrid(View &view, int x,int y,Color bg,Color fg, int lt);
    void setBg(Color bg);
    void setFg(Color fg);
    void setLt(int lt);
    void render(RenderWindow &window);
    Vector2i getSize();
    Vector2f getCellSize();
};



