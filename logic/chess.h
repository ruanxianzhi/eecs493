#ifndef CHESS_H
#define CHESS_H

#include <iostream>


class chess{
	int color;
	//Red:0, Yellow:1, Green:2, Blue:3
	int position;
	int nextposition;

	int number;
	bool passstart;
	//Image
public:
    int state;
    //At home:0, Normal:1; In "protection":2;
	chess(int colorint, int order);
	~chess();
	void calculatingnext(int);
};

#endif /* CHESS_H */