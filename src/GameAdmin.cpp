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
        counter = std::max(std::max(countInDirection(1,1),countInDirection(0,1)),std::max(countInDirection(1,-1),countInDirection(1,0)));
//        std::cout << (*table)[pY][pX] << ':' << *(*table)[pY][pX] << "\n";
        if(counter >= goal) return (*(*table)[*nY][*nY]);
    }
    if(steps >= (*table).size()*(*table)[0].size()) return 629;
    return 0;
}

int GameAdmin::countInDirection(int kx, int ky) { ///irányvektorokkal megadva az irányt
    int counter = 1;
    int playerID = *((*table)[pY][pX]);
    for(int i = 1; i < goal && pX+i*kx < (*table).size() && pY+i*ky < (*table)[pY].size() && pX+i*kx >= 0 && pY+i*ky >= 0;i++) {
        int newID = *(*table)[pY+i*ky][pX+i*kx];
        if(newID != playerID) break;
        counter++;
    }
    for(int i = 1; i < goal && pX-i*kx >= 0 && pY-i*ky >= 0 && pX-i*kx < (*table).size() && pY-i*ky  < (*table)[pY].size() ; i++) {
        int newID = *(*table)[pY-i*ky][pX-i*kx];
        if(newID != playerID) break;
        counter++;
    }
    return counter;
}
