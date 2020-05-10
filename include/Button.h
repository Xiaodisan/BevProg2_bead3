#ifndef BUTTON_H
#define BUTTON_H

#include <Widget.h>


class Button : public Widget
{
    public:
        Button() = delete;
        Button(int, int, int, int);
        virtual ~Button();

        void draw();
        void handle_event(const genv::event&);
    protected:
    private:
        bool pushed = false;
        int iR = 90, iG = 125, iB = 145; ///in
        int oR = 120, oG = 150, oB = 170; ///out
};

#endif // BUTTON_H
