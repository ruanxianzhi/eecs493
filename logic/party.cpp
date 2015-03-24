//
//  party.cpp
//  493logic
//
//  Created by Chuanshun Xia on 3/23/15.
//  Copyright (c) 2015 Chuanshun Xia. All rights reserved.
//

#include <stdio.h>
#include "party.h"

extern int alreadyfinish;


party::party(int incolor){
    partycolor = incolor;
    rank = 0;
    for(int i = 0; i < 4; i++){
        chess* inchess = new chess(incolor, i);
        ownchess.push_back(inchess);
    }
}

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