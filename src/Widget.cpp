#include "Widget.h"

Widget::Widget(int a, int b, int c, int d) :
    left(a),
    top(b),
    width(c),
    height(d) {}

Widget::~Widget(){}

bool Widget::is_selected(const int& mx, const int& my) {
    if(mx > left && mx < left + width && my > top && my < top + height) {
        focused = true;
        return true;
    }
    return false;
}

void Widget::update(){}

void Widget::unfocus(){focused = false;}
