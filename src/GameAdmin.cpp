#include "GameAdmin.h"

GameAdmin::GameAdmin(int g) :
    goal(g) {}

GameAdmin::~GameAdmin(){}

void GameAdmin::start_new(std::vector<std::vector<int*>>* t) {
    table = t;
}

int GameAdmin::evaluate() {
    return 0;
}
