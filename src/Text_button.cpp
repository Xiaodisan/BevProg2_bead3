#include "Text_button.h"

using namespace genv;

Text_button::Text_button(int a, int b, int c, int d, std::string t) :
    Button{a,b,c,d},
    label(t) {
        printed_text.open(c,d); printed_text.transparent(true);
        printed_text.load_font("LiberationSans-Regular.ttf",d/2,false);
        printed_text << move_to(c/2 - printed_text.twidth(label)/2,d/2 - printed_text.cascent()/2 - printed_text.cdescent()/2) << genv::text(label);
}

Text_button::~Text_button(){}

void Text_button::draw(){
    gout << move_to(left,top) << color(pushed*R,G,B) << box(width,height);
    gout << stamp(printed_text,left,top);
}

void Text_button::handle_event(const event& e) {
    if(e.type == ev_mouse &&
       e.pos_x > left && e.pos_x < left + width &&
       e.pos_y > top && e.pos_y < top + height &&
       e.button == btn_left) pushed = !pushed;
}

bool Text_button::is_pushed() {return pushed;}
