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

        void references(std::vector<std::vector<int*>>*&,int*&,int*&);
    protected:
    private:
        class Square : public Button{
        public:
            Square()=delete;
            Square(int,int,int,int,int*);
            virtual ~Square();

            void draw();
            void handle_event(const genv::event&);
            int* occupied_by();
        private:
            int occupied = 0; //-1: O, +1: X, 0: -
            int* next;
        };

        std::vector<std::vector<Square*>> grid;
        std::vector<std::vector<int*>> table;

        int next_player = 1;
        int number_of_moves = 0;
        int latestX = -1, latestY = -1;
//        genv::canvas circle;
//        genv::canvas cross;
        int R = 105, G = 137, B = 158;
};

#endif // AMOEBA_FIELD_H
