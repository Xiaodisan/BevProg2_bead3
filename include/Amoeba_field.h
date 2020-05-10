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
        public:
            Square()=delete;
            Square(int,int,int,int,int*);
            virtual ~Square();

            void draw();
            void handle_event(const genv::event&);
        private:
            int occupied = 0; //-1: O, +1: X, 0: -
            int* next;
        };

        std::vector<std::vector<Square*>> grid;

        int next_player = 1;
        genv::canvas circle;
        genv::canvas cross;
        int R = 105, G = 137, B = 158;
};

#endif // AMOEBA_FIELD_H
