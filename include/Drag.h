#ifndef DRAG_H
#define DRAG_H

#include <Widget.h>


class Drag : public Widget
{
    public:
        Drag() = delete;
        Drag(int,int,int,int,int=0,int=0,int=XX,int=YY);
        virtual ~Drag();
        void draw();
        void handle_event(const genv::event&);
        void drag(const int&, const int&);
        bool is_selected(const int&, const int&);
    protected:
        bool dragging = false;
        int mx, my;
        int minx, miny, maxx, maxy;
    private:
};

#endif // DRAG_H
