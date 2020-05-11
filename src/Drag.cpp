#include "Drag.h"

using namespace genv;

Drag::Drag(int x, int y, int w, int h, int nx, int ny, int xx, int xy) :
    Widget(x,y,w,h),
    minx(nx),
    miny(ny),
    maxx(xx),
    maxy(xy) {}

Drag::~Drag(){}

void Drag::draw() {
    gout << move_to(left,top) << color(10,60,80) << box(width,height);
}

void Drag::handle_event(const event& e) {
    if(e.type == ev_mouse) if(e.button == btn_left) {
        if(e.pos_x > left && e.pos_y > top && e.pos_x < left+width && e.pos_y < top+height) {
            mx = e.pos_x-left;
            my = e.pos_y-top;
            dragging = true;
        }
    }
    else if(e.button == -btn_left) dragging = false;
}

void Drag::drag(const int& evx, const int& evy){
    if(dragging){
        left = std::min(std::max(minx,evx-mx), maxx-width);
        top = std::min(std::max(miny,evy-my), maxy-height);
    }
}

bool Drag::is_selected(const int& x, const int& y) {
    return dragging;
}

int Drag::percent() {
    float prcnt = (left - minx)*100/(maxx-minx-width);
    return prcnt;
}
