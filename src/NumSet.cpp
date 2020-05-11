#include "NumSet.h"

using namespace genv;

NumSet::NumSet(int x, int y, int w, int h, int ll, int hl) :
    Widget(x,y,w,h),
    lowLimit(ll),
    highLimit(hl) {
        setter = new Drag(x+h*2/9,y+h/2,h/3,h/3,x+h*2/9,y+h/2,x+w-h,y+h*5/6);
    }

NumSet::~NumSet() {
    delete setter;
}

void NumSet::draw() {
    gout << move_to(left,top) << color(60,110,130) << box(width,height);
//    gout << move_to(left+)
    setter->draw();
}

void NumSet::handle_event(const event& ev) {
    setter->handle_event(ev);
    if(setter->is_selected(ev.pos_x,ev.pos_y)) setter->drag(ev.pos_x,ev.pos_y);
}
