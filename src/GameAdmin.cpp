#include <iostream>
#include "GameAdmin.h"

GameAdmin::GameAdmin(int g, Amoeba_field* A) :
    goal(g) {
    A->references(table,nX,nY);
    if(goal > std::max((*table).size(),(*table)[0].size())) {
        goal = std::max((*table).size(),(*table)[0].size());
        std::cerr << std::endl << "Too big goal for this game. Set to the maximum: " << goal << std::endl;
    }
}

GameAdmin::~GameAdmin(){
    ///nem kell a pointereket törölni, mivel 'rendes' változókra mutatnak
}

int GameAdmin::evaluate() {
    int counter = 1;
    if(nX && nY) if((*nX) != pX || (*nY) != pY) {
        pX = *nX; pY = *nY;
        steps++;
//        std::cout << (*table)[pY][pX] << ':' << *(*table)[pY][pX] << "\n";
    }
    if(steps >= (*table).size()*(*table)[0].size()) return 629;
    return 0;
}

int GameAdmin::countInDirection(int kx, int ky) { ///irányvektorokkal megadva az irányt
    int counter = 1;
    int playerID = *(*table)[*nY][*nX];
    for(int i = 1; i < goal && (*nY)+i*kx < (*table).size() && (*nX)+i*ky < (*table)[*nY].size() ;i++) {
        if(*(*table)[(*nY)+i*ky][(*nX)+i*kx] != playerID) break;
        counter++;
    }
    for(int i = 1; i < goal && (*nY)-i*kx >= 0 && (*nX)-i*ky > 0; i++) {
        if(*(*table)[(*nY)+i*ky][(*nX)+i*kx] != playerID) break;
        counter++;
    }
    return counter;
}
