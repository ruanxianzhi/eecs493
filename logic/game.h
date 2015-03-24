#include <iostream>
#include <vector>
#include "party.h"

using namespace std;

class game{
	int numplayer;
    int gamemode;
    vector<party*> allparty;

public:
	game(int number, int mode);
	~game();
	void init();
    bool isEnd();
};
