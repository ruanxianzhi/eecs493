//
//  main.cpp
//  493logic
//
//  Created by Chuanshun Xia on 3/23/15.
//  Copyright (c) 2015 Chuanshun Xia. All rights reserved.
//

#include <iostream>
#include "game.h"

int main(int argc, const char * argv[]) {
    game *newgame = new game(1,2);
    newgame->init();
}
