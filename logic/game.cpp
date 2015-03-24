#include "game.h"
#include <iostream>

extern int alreadyfinish;

game::game(int number, int mode){
	numplayer = number;
    gamemode = mode;
}

void game::init(){
	for(int i = 0; i < numplayer; i++){
        party *newpart = new party(i);
        allparty.push_back(newpart);
    }
}

bool game::isEnd(){
    if(gamemode==1){
        if(alreadyfinish == 3) return true;
        else return false;
    }
    else{
        if(alreadyfinish == 1) return true;
        else return false;
    }
}