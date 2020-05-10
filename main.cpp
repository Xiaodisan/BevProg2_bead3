#include <iostream>

#include "master.h"

using namespace genv;

int game_loop() {
    gout.open(XX,YY);
    event ev;
    gin.timer(40);
    gout << move_to(0,0) << color(108, 187, 164) << box(XX,YY) << color(255,255,255);
    Amoeba_field jatek(10,10,XX-20,YY-20,11);
    while(gin >> ev && ev.keycode != key_escape) {
        if(ev.type == ev_timer) {
            jatek.update();
            jatek.draw();
            gout << refresh;
        }
        else if(ev.type == ev_mouse) {
            jatek.handle_event(ev);
        }
    }
}

int main()
{
    int result = game_loop();
    std::cout << result;
    return 0;
}
