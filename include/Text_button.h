#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include <Button.h>


class Text_button : public Button
{
    public:
        Text_button() = delete;
        Text_button(int,int,int,int,std::string="");
        virtual ~Text_button();

        void draw();
        void handle_event(const genv::event&);
        bool is_pushed();
    protected:
    private:
        bool pushed = false;
        int R = 200, G = 230, B = 250;
        std::string label = "";
        genv::canvas printed_text;
};

#endif // TEXT_BUTTON_H
