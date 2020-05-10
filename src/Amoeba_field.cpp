#include "Amoeba_field.h"

#include <iostream>

using namespace genv;

Amoeba_field::Amoeba_field(int nx, int ny, int sx, int sy, int ax, int ay, int d) :
    Widget(nx,ny,sx,sy) {
    int dx = sx / ((10+d)*ax); std::cout << dx;
    int dy = ay <= 0 ? sy / ((10+d)*ax) : sy / ((10+d)*ay);
    for(int i = 0; ay <= 0 ? i < ax : i < ay; i++) {
        std::vector<Square*> temp;
        for(int j = 0; j < ax; j++) {
            temp.push_back(new Square(nx + (j+1)*(d)*dx + j*10*dx, ny + (i+1)*d*dy + i*10*dy, 10*dx, 10*dy, &next_player));
        }
        grid.push_back(temp);
    }
}


Amoeba_field::~Amoeba_field(){}

void Amoeba_field::draw() {
    gout << move_to(left,top) << color(R,G,B) << box(width,height);
    for(std::vector<Square*> sQ : grid)
        for(Square* S : sQ) S->draw();
}

void Amoeba_field::handle_event(const event& e) {
    if(e.type == ev_mouse &&
       e.pos_x > left && e.pos_x < left + width &&
       e.pos_y > top && e.pos_y < top + height &&
       e.button == btn_left)
       {
           for(std::vector<Square*> sQ : grid)
            for(Square* S : sQ) S->handle_event(e);
       }
}

void Amoeba_field::update() {
}

Amoeba_field::Square::Square(int a, int b, int c, int d, int* n) :
    Button(a,b,c,d),
    next(n) {}

Amoeba_field::Square::~Square(){}

void Amoeba_field::Square::draw(){
    std::cout << 255*occupied*0.5+127.5;
    gout << move_to(left,top) << color(255*occupied*0.5+127.5,255*occupied*0.5+127.5,255*occupied*0.5+127.5) << box(width,height);
}

void Amoeba_field::Square::handle_event(const event& e) {
    if(e.type == ev_mouse &&
       e.pos_x > left && e.pos_x < left + width &&
       e.pos_y > top && e.pos_y < top + height &&
       e.button == btn_left) {occupied = *next; *next *= -1;}
}
