#include <stdio.h>
#include "party.h"


extern int alreadyfinish;

party::party(int incolor)
{
    partycolor = incolor;
    rank = 0;
    for(int i = 0; i < 4; i++){
        chess *inchess = new chess(incolor, i);
        ownchess.push_back(inchess);
    }
}

party::~party(){

}

bool party::isFinish(){

   for(int i = 0; i < 4; i++){
       if(ownchess[i]->state !=4 ) return false;
   }
    return true;
}
