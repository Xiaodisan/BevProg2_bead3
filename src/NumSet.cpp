#include "NumSet.h"

using namespace genv;

NumSet::NumSet(int x, int y, int w, int h, int* nS, std::string nl, int ll, int hl) :
    Widget(x,y,w,h),
    setNum(nS),
    label(nl),
    lowLimit(ll),
    highLimit(hl) {
        setter = new Drag(x+h*2/9,y+h*5/9,h/3,h/3,x+h*2/9,y+h*5/9,x+w-h,y+h*8/9);
    }

NumSet::~NumSet() {
    delete setter;
}

void NumSet::draw() {
    gout << move_to(left,top) << color(60,110,130) << box(width,height);
    gout << move_to(left+height*2/9,top+height*25/36) << color(0,30,40) << box(width-height*11/9,height/9);
    gout << move_to(left+width-height/2-gout.twidth(std::to_string(*setNum))/2,top+height/2+gout.cdescent()) << color(180,205,225) << text(std::to_string(*setNum));
    gout << move_to(left+height/2,top+height/9+gout.cascent()) << text(label);
    setter->draw();
}

void NumSet::handle_event(const event& ev) {
    setter->handle_event(ev);
    if(setter->is_selected(ev.pos_x,ev.pos_y)) setter->drag(ev.pos_x,ev.pos_y);
    *setNum = lowLimit + (highLimit-lowLimit)*(setter->percent())/100;
}
