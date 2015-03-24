//
//  party.h
//  493logic
//
//  Created by Chuanshun Xia on 3/23/15.
//  Copyright (c) 2015 Chuanshun Xia. All rights reserved.
//

#ifndef _93logic_party_h
#define _93logic_party_h

#include "chess.h"

#include <vector>

using namespace std;

class party{
    vector<chess*> ownchess;
    int partycolor;
    int rank;
    bool finish;
public:
    party(int);
    ~party();
    bool isFinish();
};

#endif
