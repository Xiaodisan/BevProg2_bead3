#include <iostream>
#include "GameAdmin.h"

GameAdmin::GameAdmin(int g, Amoeba_field* A) :
    goal(g) {
    A->references(table,nX,nY);
}

GameAdmin::~GameAdmin(){}

int GameAdmin::evaluate() {
    if(nX && nY) if((*nX) != pX || (*nY) != pY) {
        pX = *nX; pY = *nY;
        steps++;
        std::cout << *(*table)[pY][pX] << "\n";
    }
    if(steps >= (*table).size()*(*table)[0].size()) return 629;
    return 0;
}
