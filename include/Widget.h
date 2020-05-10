#ifndef WIDGET_H
#define WIDGET_H

#define XX 400
#define YY 400

#include "graphics.hpp"

class Widget
{
    public:
        Widget() = delete;
        Widget(int,int,int,int);
        virtual ~Widget();

        virtual void draw() = 0;
        virtual void handle_event(const genv::event&) = 0;
        virtual void update();

        virtual bool is_selected(const int&, const int&);
        virtual void unfocus();
    protected:
        int left, top, width, height;
        bool focused = false;
    private:
};

#endif // WIDGET_H
