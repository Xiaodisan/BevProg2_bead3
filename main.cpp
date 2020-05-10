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

int menu() {
    gout.open(XX,YY);
    event ev;
    gin.timer(40);
    gout << move_to(0,0) << color(108, 187, 164) << box(XX,YY) << color(255,255,255);
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
