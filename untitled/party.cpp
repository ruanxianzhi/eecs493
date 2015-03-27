
#include <stdio.h>
#include "party.h"


extern int alreadyfinish;
extern QTimer *timer;


party::party(int incolor, QWidget *parent)
    : QWidget(parent)
{
    partycolor = incolor;
    rank = 0;
    timer = new QTimer;
    for(int i = 0; i < 4; i++){
        chess* inchess = new chess(incolor, i);
        ownchess.push_back(inchess);
        timer->setInterval(1000);
        connect(timer, SIGNAL(timeout()), inchess, SLOT(move()));
    }
}

//party::~party(){

//}

bool party::isFinish(){
    if(finish==false){
        for(int i = 0; i < 4; i++){
            if(ownchess[i]->state !=4 ) return false;
        }
        rank = alreadyfinish + 1;
        alreadyfinish++;
        finish = true;
        return true;
    }
    else{
        return true;
    }
}
