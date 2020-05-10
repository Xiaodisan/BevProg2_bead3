#ifndef GAMEADMIN_H
#define GAMEADMIN_H

#include <Amoeba_field.h>

class GameAdmin
{
    public:
        GameAdmin()=delete;
        GameAdmin(int);
        virtual ~GameAdmin();

        void start_new(std::vector<std::vector<int*>>*);
        int evaluate();
    protected:

    private:
        int goal;
        std::vector<std::vector<int*>>* table;
};

#endif // GAMEADMIN_H
