#include "Amoeba_field.h"

using namespace genv;

Amoeba_field::Amoeba_field(int nx, int ny, int sx, int sy, int ax, int ay, int d) :
    Widget(nx,ny,sx,sy) {
    for(int i = 0; i < ax; i++) {
        for(int j = 0; ay <= 0 ? j < ax : j < ay; j++) {

        }
    }
}


Amoeba_field::~Amoeba_field(){}

void Amoeba_field::draw() {
}

void Amoeba_field::handle_event(const event& e) {
}

void Amoeba_field::update() {
}
