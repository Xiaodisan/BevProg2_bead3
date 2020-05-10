#include <iostream>
#include "GameAdmin.h"

GameAdmin::GameAdmin(int g, Amoeba_field* A) :
    goal(g) {
    A->references(table,nX,nY);
    if(nX) std::cout << "OK";
}

GameAdmin::~GameAdmin(){}

int GameAdmin::evaluate() {
    if(nX && nY) if((*nX) != pX || (*nY) != pY) {
        pX = *nX; pY = *nY;
        steps++;
    }
    if(steps > 5) return 1;
    return 0;
}
