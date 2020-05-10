#ifndef GAMEADMIN_H
#define GAMEADMIN_H

#include <Amoeba_field.h>

class GameAdmin
{
    public:
        GameAdmin()=delete;
        GameAdmin(int,Amoeba_field*);
        virtual ~GameAdmin();

        void start_new();
        int evaluate();
    protected:

    private:
        int goal;
        std::vector<std::vector<int*>>* table;
        int pX = -1, pY = -1;
        int* nX, *nY;
        int steps = 0;
};

#endif // GAMEADMIN_H
