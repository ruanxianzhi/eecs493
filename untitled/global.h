#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>
#include <vector>
#include <QTimer>
using namespace std;

const int flyminus = 52;
int alreadyfinish = 0;
int baseaddr[4] = {0, -1, -2, -3};
int baseadding[4] = {0, 14, 28, 42};
int turnaroundpoint[4] = {50, 11, 24, 37};
int turnaroundadding[4] = {20, 41, 34, 27};
int flybase1[4] = {14, 27, 40, 1};
int flybase2[4] = {18, 31, 44, 5};
int flyend[4] = {30, 43, 4, 17};
int colorjump[4] = {2, 3, 0, 1};
int endpoint[4] = {76, 58, 64, 70};

QTimer *timer;// = new QTimer();

#endif // GLOBAL_H

