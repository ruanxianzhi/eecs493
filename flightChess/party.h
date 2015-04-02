#ifndef PARTY_H
#define PARTY_H
#include "chess.h"
#include <QWidget>
#include <QtWidgets>
#include <QMouseEvent>
#include <QColorDialog>
#include <vector>

using namespace std;

class party{

protected:
    int partycolor;
    int rank;
    bool finish;
public:
    party(int incolor);
    ~party();
    bool isFinish();
    vector<chess*> ownchess;
};

#endif // PARTY_H

