#ifndef PARTY_H
#define PARTY_H
#include "chess.h"
#include <QWidget>
#include <QtWidgets>
#include <QMouseEvent>
#include <QColorDialog>
#include <vector>

using namespace std;

class party : public QWidget{

protected:
    vector<chess*> ownchess;
    int partycolor;
    int rank;
    bool finish;
public:
    party(int incolor, QWidget *parent = 0);
    //~party();
    bool isFinish();
};

#endif // PARTY_H

