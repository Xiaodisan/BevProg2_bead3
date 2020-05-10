#include <iostream>

#include "master.h"

using namespace genv;

int game_loop(event& ev, int tableX = 15, int goal = 5, int tableY = 15) {
    Amoeba_field jatek(10,10,XX-20,YY-20,tableX,tableY);
    GameAdmin game(goal,&jatek);
    while(gin >> ev && ev.keycode != key_escape) {
        if(ev.type == ev_timer) {
            jatek.update();
            jatek.draw();
            gout << refresh;
            int result = game.evaluate();
            if(result != 0) return result;
        }
        else if(ev.type == ev_mouse) {
            jatek.handle_event(ev);
        }
    }
    return 0;
}

int menu() { ///b�v�t�sre, param�terez�sre lehet�s�g
    gout.open(XX,YY);
    event ev;
    gin.timer(40);
//    gout << move_to(0,0) << color(108, 187, 164) << box(XX,YY) << color(255,255,255);
    canvas background; background.open(XX,YY); {
        background << color(100,100,100);
        background << move_to(0,0) << box(XX,YY);
        background << color(200,200,200);
        float XXX = XX, YYY = YY;
        for(int x = 0; x < XXX; x++) {
            for(int y = 0; y < YYY; y++) {
                background << move_to(x,y) << color(100,100,100);
///             if(y > (x1-x0)/(y1-y0) * (x-x0) + y0) background << color(140,140,140);
                if(y > XXX*x/(YYY*3) + YYY*2/15) background << color(140,140,140);
                if(y > (XXX*3/10)/(0-YYY/2) * (x) + YYY/2) background << color(70,70,70);
                if(y > (XXX*3/10)/(0-YYY/2) * (x) + YYY*4/5 && x > XXX/2) background << color(80,80,80);
                if(y > (XXX*3/10)/(YYY*1/2) * (x-XXX/2) + YYY/2 && x > XXX/2) background << color(70,70,70);
                if(y > (XXX*1/2)/(YYY*1/2) * (x) + YYY/2) background << color(170,170,170);
                background << dot;
            }
        }
    }
    while(gin >> ev && ev.keycode != key_escape) {
        if(ev.type == ev_timer) {
            gout << stamp(background,0,0);
            gout << refresh;
        }
    }
    return game_loop(ev);
}

int main()
{
    int result = menu();
    std::cout << std::endl;
    if(result == 1) std::cout << "WHITE WON";
    else if(result == -1) std::cout << "BLACK WON";
    else if(result == 629) std::cout << "DRAW";
    return 0;
}
