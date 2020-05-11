#ifndef NUMSET_H
#define NUMSET_H

#include <Widget.h>
#include <Drag.h>

class NumSet : public Widget
{
    public:
        NumSet() = delete;
        NumSet(int,int,int,int,int*,std::string label="",int=0,int=30);
        virtual ~NumSet();

        void draw();
        void handle_event(const genv::event&);
    protected:
    private:
        std::string label;
        int* setNum;
        int lowLimit, highLimit;
        Drag* setter;
};

#endif // NUMSET_H
