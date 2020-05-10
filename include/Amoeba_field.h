#ifndef AMOEBA_FIELD_H
#define AMOEBA_FIELD_H

#include <Widget.h>
#include <Button.h>
#include <vector>

class Amoeba_field : public Widget
{
    public:
        Amoeba_field() = delete;
        Amoeba_field(int,int,int,int,int,int=0,int=2);
        virtual ~Amoeba_field();

        void draw();
        void handle_event(const genv::event&);
        void update();


    protected:
    private:
        class Square : public Button{
        private:

        public:

        };

        std::vector<std::vector<Square>> grid;
        bool pushed;
        genv::canvas circle;
        genv::canvas cross;
};

#endif // AMOEBA_FIELD_H
