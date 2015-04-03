#include "chess.h"
#include "global.h"
#include <math.h>
#include <cmath>

extern QTimer *timer;
extern QTimer* updatetimer;
extern QTimer *backtimer;

chess::chess(int colornum, int order, QGLWidget *parent)
    : QGLWidget(parent)
{
    color = colornum;
    number = order;
    state = 0;
    state2 = 0;
    position = -1;
    nextone = -1;
    nextposition = -1;
    t=0;
    currentx = startx[color][number];
    currenty = starty[color][number];
    if(colornum == 0) passstart = true;
    else passstart = false;
}

chess::~chess(){

}

void chess::calculatingnextone(){
    if (position == -1) nextone = baseaddr[color];
    else if (position == baseaddr[color]) nextone =  1 + baseadding[color];
    else if (position == turnaroundpoint[color]) nextone = position + turnaroundadding[color]+1;
    else if (position == flybase2[color] && nextposition == flyend[color]) nextone = flyend[color];
    else if (position == 52) nextone=1;
    else if (state2) nextone--;
    else nextone++;
    if (nextone==endpoint[color]) state2=1;
    //cerr<<passstart2;
    if(position!=nextone){
        speedx = 0.5f*(coordinatex[nextone]-currentx);
        speedy = 0.5f*(coordinatey[nextone]-currenty);
    }
    //std::cerr<<"next"<<nextone;
}

void chess::calculatingnext(int forward){//std::cerr<<"aaa";
    if (forward == 7) {
            nextposition=-1;
            nextone=-1;
            speedx = 0.5f*(startx[color][number]-currentx);
            speedy = 0.5f*(starty[color][number]-currenty);
            return;
    }
    if(state == 0){
        if(forward == 6){
            nextposition = baseaddr[color];
            state = 1;
        }
    }
    //Ready to begin
    else if (state==1){
         if((forward == 2)||(forward == 6)){
            nextposition =  forward + 4 + baseadding[color];
         }
         else{
            nextposition =  forward + baseadding[color];
         }
         state = 2;
    }
    //normal
    else if (state==2){
        if((position + forward == flybase1[color])||(position + forward == flybase2[color])){
            nextposition = flyend[color];
            if(color == 2) passstart = true;
        }
        else if(((position + forward - colorjump[color]) % 4 == 0) && (position + forward!=turnaroundpoint[color])){
            nextposition = position + forward + 4;
        }
        else{
            nextposition = position + forward;
        }

        if((nextposition >= turnaroundpoint[color]) && passstart == true){
            if(nextposition != turnaroundpoint[color]){
                if(((position + forward - colorjump[color]) % 4 == 0) && (position + forward < turnaroundpoint[color])){
                    nextposition = position + forward + 4 + turnaroundadding[color];
                }
                else{
                    nextposition = position + forward + turnaroundadding[color];
                }
            }
            state = 3;
        }
        if(color != 0 && nextposition > 52 && state!=3){
            nextposition = nextposition - flyminus;
            passstart = true;
        }
    }
    //In protection
    else if(state == 3){
        if(position == turnaroundpoint[color]){
            nextposition = position + turnaroundadding[color] + forward;
            if(nextposition == endpoint[color]){
                state = 4;
            }
        }
        else{
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
    std::cerr<<"next"<<nextposition<<"\n";
    if(position!=nextposition) calculatingnextone();
    else{
        updatetimer->stop();
        timer->start();
    }
}

void chess::move(){
    if (position!=nextone && t<2) {
        currentx += speedx;
        currenty += speedy;//std::cerr<<"hhh";
        t++;
    }
    else {
        t=0;
        position = nextone;//std::cerr<<"pos"<<position;
        if (nextone == nextposition) {
            state2 = 0;
            if (backtimer->isActive()) {
                backtimer->stop();
                state = 0;
            }
            else {
                updatetimer->stop();
                timer->start();
            }
        }
        else calculatingnextone();
    }
}

void chess::draw(){
    //std::cerr<<"number"<<number<<"currentx"<<currentx<<"currenty"<<currenty<<"\n";
    glBegin(GL_POLYGON);
    qglColor(Qtcolor[color]);
    for (float radian=0.0; radian<2*3.14159; radian+=0.05)
    {
        glTexCoord2f(currentx-0.2f+0.5f*cos(radian), currenty-0.2f+0.5f*sin(radian));
        glVertex3f(currentx+0.5f*cos(radian), currenty+0.5f*sin(radian),1.3f);
    }
    glEnd();

    glBegin(GL_QUADS);
    qglColor(Qt::white);
    for (float radian=0.0; radian<2*3.14159; radian+=0.05)
    {
        glVertex3f(currentx+0.5f*cos(radian), currenty+0.5f*sin(radian),1.0f);
        glVertex3f(currentx+0.5f*cos(radian+0.05), currenty+0.5f*sin(radian+0.05),1.0f);
        glVertex3f(currentx+0.5f*cos(radian+0.05), currenty+0.5f*sin(radian+0.05),1.3f);
        glVertex3f(currentx+0.5f*cos(radian), currenty+0.5f*sin(radian),1.3f);
    }
    glEnd();
}
