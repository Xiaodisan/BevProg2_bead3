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

int menu() { ///bõvítésre, paraméterezésre lehetõség
    gout.open(XX,YY);
    event ev;
    gin.timer(40);
    canvas background; background.open(XX,YY); { ///háttér kialakítása - elhalasztva
        background << color(100,100,100);
        background << move_to(0,0) << box(XX,YY);
        background << color(200,200,200);
        float XXX = XX, YYY = YY;
        for(int x = 0; x < XXX; x++) {
            for(int y = 0; y < YYY; y++) {
                background << move_to(x,y) << color(50,85,110);
///             if(y > (x1-x0)/(y1-y0) * (x-x0) + y0) background << color(140,140,140);
//                if(y > XXX*x/(YYY*3) + YYY*2/15) background << color(140,140,140);
//                if(y > (XXX*3/10)/(0-YYY/2) * (x) + YYY/2) background << color(70,70,70);
//                if(y > (XXX*3/10)/(0-YYY/2) * (x) + YYY*4/5 && x > XXX/2) background << color(80,80,80);
//                if(y > (XXX*3/10)/(YYY*1/2) * (x-XXX/2) + YYY/2 && x > XXX/2) background << color(70,70,70);
//                if(y > (XXX*1/2)/(YYY*1/2) * (x) + YYY/2) background << color(170,170,170);
                background << dot;
            }
        }
    }
    std::vector<Widget*> widgetek; { ///menü widgetei
//        Widget* kreator;
//        kreator = new ...;
//        widgetek.push_back(kreator);
    }
    Text_button* start_button = new Text_button(XX*11/16,YY*7/16,XX*2/8,YY*1/8,"START");
    bool start_soon = false;
    int count_down = 7;
    while(gin >> ev && ev.keycode != key_escape && count_down > 0) {
        if(ev.type == ev_timer) {
            gout << stamp(background,0,0);
            for(Widget* w : widgetek) if(w != nullptr) w->draw();
            if(start_button != nullptr) start_button->draw();
            gout << refresh;
            if(start_soon) count_down--;
        }
        else if(ev.type == ev_mouse) {
            for(Widget* w : widgetek) if(w != nullptr) w->handle_event(ev);
            if(start_button != nullptr) start_button->handle_event(ev);
        }
         if(start_button != nullptr) if(start_button->is_pushed()) start_soon = true;
    }
    for(Widget* w : widgetek) if(w != nullptr) delete w;
    delete start_button;
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
