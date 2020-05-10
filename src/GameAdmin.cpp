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
    if(nX && nY) if((*nX) != pX || (*nY) != pY) {
        pX = *nX; pY = *nY;
        steps++;
        std::cout << *(*table)[pY][pX] << "\n";
    }
    if(steps >= (*table).size()*(*table)[0].size()) return 629;
    return 0;
}
