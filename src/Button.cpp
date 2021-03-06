#include "Button.h"

using namespace genv;

Button::Button(int a, int b, int c, int d) :
    Widget(a,b,c,d) {}

Button::~Button(){}

void Button::draw() {
    gout << move_to(left,top) << (pushed ? color(iR,iG,iB) : color(oR,oG,oB)) << box(width,height);
}

void Button::handle_event(const event& e){
    if(e.type == ev_mouse &&
       e.pos_x > left && e.pos_x < left + width &&
       e.pos_y > top && e.pos_y < top + height &&
       e.button == btn_left) pushed = !pushed;
}
