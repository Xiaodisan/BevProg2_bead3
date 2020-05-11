#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include <Widget.h>


class Text_button : public Widget
{
    public:
        Text_button() = delete;
        Text_button(int,int,int,int,std::string="");
        virtual ~Text_button();

        void draw();
        void handle_event(const genv::event&);
        bool is_selected(const int&,const int&);
        void unfocus();
    protected:
    private:
        bool pushed = false;
        int R = 60, G = 110, B = 130;
        std::string label = "";
        genv::canvas printed_text;
};

#endif // TEXT_BUTTON_H
