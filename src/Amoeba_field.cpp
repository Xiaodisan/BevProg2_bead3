#include "Amoeba_field.h"

#include <iostream>

using namespace genv;

Amoeba_field::Amoeba_field(int nx, int ny, int sx, int sy, int ax, int ay, int d) :
    Widget(nx,ny,sx,sy) {
    float dx = sx * 1.0 / (10*ax + d*ax + d); std::cout << sx << " " << ax << " " << dx;
    float dy = ay <= 0 ? sy * 1.0 / (10*ax + d*ax + d) : sy * 1.0 / (10*ay + d*ay + d);
    for(int i = 0; ay <= 0 ? i < ax : i < ay; i++) {
        std::vector<Square*> temp;
        std::vector<int*> tempTable;
        for(int j = 0; j < ax; j++) {
            temp.push_back(new Square(nx + d*dx + j*(10+d)*dx, ny + d*dy + i*(10+d)*dy, 10*dx, 10*dy, &next_player));
            tempTable.push_back(temp[temp.size()-1]->occupied_by());
        }
        grid.push_back(temp);
        table.push_back(tempTable);
    }
}

Amoeba_field::~Amoeba_field(){
    ///a table-t nem kell törölni, mivel a Square mezöire mutatnak, ahol 'rendes' változók => a Square törlésével az is törlõdik
    for(signed i = grid.size()-1; i >= 0; i--) {
        for(signed j = grid[i].size()-1; j >= 0; j--) {
            delete grid[i][j];
        }
    }
}

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
           for(int i = 0; i < grid.size(); i++) for(int j = 0; j < grid[i].size(); j++)
           {
               int temp = next_player;
               grid[i][j]->handle_event(e);
               if(next_player != temp)
               {
                   latestX = j; latestY = i;
                   number_of_moves++;
               }
           }
       }
}

void Amoeba_field::update() {
//    if(number_of_moves >= grid.size()*grid[0].size()) std::cout << "DRAW";
//    if(latestY > -1 && latestY < grid.size() && latestX > -1 && latestX < grid[0].size())
//    {
//        int counter = 0;
//        for(int cy = 0; cy <  grid.size(); cy++)
//        {
//            if(*grid[cy][latestX]->occupied_by() == *grid[latestY][latestX]->occupied_by()) counter++;
//            else counter = 0;
//            if(counter >= 5) break;
//        }
//        if(counter >= 5) std::cout << *grid[latestY][latestX]->occupied_by() << " WON";
//    }
}

void Amoeba_field::references(std::vector<std::vector<int*>>*& t, int*& nX, int*& nY) {
    t = &table;
    nX = &latestX;
    nY = &latestY;
    std::cout << std::endl << "References given" << std::endl;
}

Amoeba_field::Square::Square(int a, int b, int c, int d, int* n) :
    Button(a,b,c,d),
    next(n) {}

Amoeba_field::Square::~Square(){}

void Amoeba_field::Square::draw(){
    gout << move_to(left,top) << color(255*occupied*0.5+127.5,255*occupied*0.5+127.5,255*occupied*0.5+127.5) << box(width,height);
}

void Amoeba_field::Square::handle_event(const event& e) {
    if(e.type == ev_mouse &&
       e.pos_x > left && e.pos_x < left + width &&
       e.pos_y > top && e.pos_y < top + height &&
       e.button == btn_left &&
       occupied == 0)
        {
            occupied = *next;
            *next *= -1;
        }
}

int* Amoeba_field::Square::occupied_by() {return &occupied;}
