#include "chess.h"
#include "global.h"


chess::chess(int colornum, int order){
	color = colornum;
    number = order;
	state = 0;
	position = -1;
	if(colornum == 0) passstart = true;
	else passstart = false;
}

chess::~chess(){

}

void chess::calculatingnext(int forward){
	//At home
	if(state == 0){
		if(forward == 6){
			nextposition = baseaddr[color];
			state = 1;
		}
	}
	//Ready to begin
	else if (state==1){
		 if((forward == 2)||(forward == 6)){
		 	nextposition = position + forward + 4 + baseadding[color];
		 }
		 else{
		 	nextposition = position + forward + baseadding[color];
		 }
	}
	//normal
	else if (state==2){
		if((position + forward == flybase1[color])||(position + forward == flybase2[color])){
			nextposition = flyend[color];
		}
		else if(((position + forward - colorjump[color]) % 4 == 0) && (position + forward!=turnaroundpoint[color])){
			nextposition = position + forward + 4;
		}
		else{
		    nextposition = position + forward;
		}
		if((nextposition >= turnaroundpoint[color]) && passstart == true){
			if(((position + forward - colorjump[color]) % 4 == 0)&& (position + forward!=turnaroundpoint[color])){
				nextposition = position + forward + 4 - turnaroundpoint[color] + turnaroundadding[color];
			}
			else{
		    	nextposition = position + forward - turnaroundpoint[color] + turnaroundadding[color];
			}
			state = 3;
		}
		if(color != 0 && position+forward > 52 && state!=3){
			position = position - flyminus;
			passstart = true;
		}
	}
	//In protection
	else if(state == 3){
		if(position + forward == endpoint[color]){
			nextposition = endpoint[color];
			state = 4;
			//finish();
		}
		else if(position + forward < endpoint[color]){
			nextposition = position + forward;
		}
		else{
			nextposition = endpoint[color] - (forward - (endpoint[color] - position)) ;
		}
	}
}