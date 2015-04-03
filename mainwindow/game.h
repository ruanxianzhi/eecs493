#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "party.h"

using namespace std;

class game{
    int numplayer;
    int gamemode;

public:
    game(int number, int mode);
    ~game();
    void init();
    bool isEnd();
    vector<party*> allparty;
};

#endif // GAME_H

