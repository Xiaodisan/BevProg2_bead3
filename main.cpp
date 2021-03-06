#include <iostream>

#include "master.h"

using namespace genv;

int game_loop(event& ev, int tableX = 15, int goal = 5, int tableY = 15) {
    Amoeba_field jatek(10,10,XX-20,YY-20,tableX,tableY);
    GameAdmin game(goal,&jatek);
    while(gin >> ev && ev.keycode != key_escape && ev.keycode != key_backspace) {
        if(ev.type == ev_timer) {
            jatek.update();
            jatek.draw();
            gout << refresh;
            int result = game.evaluate();
            if(result != 0) {
                for(int i = 20; gin >> ev && ev.type != ev_key && ev.button <= 0 && i > 0;) {if(ev.type == ev_timer) i--;}
                return result;
            }
        }
        else if(ev.type == ev_mouse) {
            jatek.handle_event(ev);
        }
    }
    if(ev.keycode == key_escape) return -10;
    return 0;
}

void background_refresh(canvas& background,std::string mainTitle,std::string subTitle) {
/// if(y > (x1-x0)/(y1-y0) * (x-x0) + y0) background << color(140,140,140);
    background.load_font("LiberationSans-Regular.ttf",YY*3/30);
    background << move_to(0,0) << color(40,90,110) << box(XX,YY);
    background << move_to(XX/2 - background.twidth(mainTitle)/2,YY*1/30) << color(180,205,225) << text(mainTitle);
    background << move_to(0,YY*1/30+background.cascent()+background.cdescent());
    background.load_font("LiberationSans-Regular.ttf",YY*1/30);
    background << move(XX/2 - background.twidth(subTitle)/2,0) << text(subTitle);

}

int menu_loop() {
    gout.open(XX,YY);
    event ev;
    gin.timer(40);

    std::string mainTitle = "AMOEBA";
    std::string subTitle = " ";

    canvas background;
    background.open(XX,YY);
    background_refresh(background,mainTitle,subTitle);

    std::string plusz = "White"; ///a 'feh�r' j�t�kos (1-es visszat�r�si �rt�k game_loop-b�l, ha � nyer)
    std::string minusz = "Black"; ///a 'fekete' j�t�kos (-1-es visszat�r�si �rt�k game_loop-b�l, ha � nyer)
    int tableX = 15, goal = 5, tableY = 15;

    std::vector<Widget*> widgetek; {
        Widget* kreator;
        kreator = new Text_button(XX*11/16,YY*7/16,XX*2/8,YY*1/8,"START");
        widgetek.push_back(kreator);
        kreator = new NumSet(XX*2/30,YY*9/24,XX/2,YY/15,&tableX,"Number of columns",3,30);
        widgetek.push_back(kreator);
        kreator = new NumSet(XX*2/30,YY*13/24,XX/2,YY/15,&tableY,"Number of rows",3,30);
        widgetek.push_back(kreator);
        kreator = new NumSet(XX*2/30,YY*17/24,XX/2,YY/15,&goal,"Target size of a winning set",3,10);
        widgetek.push_back(kreator);
    }

    int countDown = 8;

    while(ev.keycode != key_escape && gin >> ev) {
        if(ev.type == ev_timer) { ///widgetek kirajzol�sa, j�t�k ind�t�s (+k�sleltet�s)
            gout << stamp(background,0,0);
            for(signed i = widgetek.size()-1; i >= 0; i--) if(widgetek[i] != nullptr) {
                widgetek[i]->draw();
                if(widgetek[i]->is_selected(-1,-1)) countDown--;
            }
            if(countDown <= 0) {
                int winner = game_loop(ev,tableX,goal,tableY);
                if(winner == 1) subTitle = plusz + " won";
                else if(winner == -1) subTitle = minusz + " won";
                else subTitle = " ";
                if(winner == -10) ev.keycode = key_escape;
                background_refresh(background,mainTitle,subTitle);
                for(Widget* w : widgetek) if(w != nullptr) w->unfocus();
                countDown = 8;
            }
            gout << refresh;
        }
        else if(ev.type == ev_mouse) { ///widgetek esem�nykezel�se
            for(signed i = widgetek.size()-1; i >= 0; i--) if(widgetek[i] != nullptr) {
                widgetek[i]->handle_event(ev);
                if(widgetek[i]->is_selected(ev.pos_x,ev.pos_y)) {
                    Widget* temp = widgetek[i];
                    widgetek.erase(widgetek.begin()+i);
                    widgetek.push_back(temp);
                    break;
                }
            }
        }
    }
    for(signed i = widgetek.size()-1; i > 0; i--) if(widgetek[i] != nullptr)
    {
        delete widgetek[i]; widgetek.erase(widgetek.begin()+i);
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL,"HUN");
    int manuReturn = menu_loop();
    return 0;
}
