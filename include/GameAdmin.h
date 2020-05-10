#ifndef GAMEADMIN_H
#define GAMEADMIN_H

#include <Amoeba_field.h>

class GameAdmin
{
    public:
        GameAdmin()=delete;
        GameAdmin(int);
        virtual ~GameAdmin();

        int evaluate(std::vector<std::vector<int*>>*);
    protected:

    private:
        int goal;
};

#endif // GAMEADMIN_H
