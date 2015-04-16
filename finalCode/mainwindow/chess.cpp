#include "chess.h"
#include "global.h"
#include <math.h>
#include <cmath>
#include <endwindow.h>



extern QTimer* updatetimer;
extern QTimer *backtimer;
extern bool boom;
extern bool finish;
extern QString username[4];

chess::chess(int colornum, int order, QGLWidget *parent)
    : QGLWidget(parent)
{
    color = colornum;
    number = order;
    counter = 0;
    state = 0;
    state2 = 0;
    position = -1;
    nextone = -1;
    nextposition = -1;
    height = 1.0;
    height2 = 1.0;
    t=0;
    currentx = startx[color][number];
    currenty = starty[color][number];
    if(colornum == 0) passstart = true;
    else passstart = false;
}

chess::~chess(){

}

void chess::calculatingnextone(){
    if (position == jumposition && jumposition == flybase1[color]) nextone = flybase2[color];
    else if (position == jumposition) nextone = nextposition;
    else if (position == -1) nextone = baseaddr[color];
    else if (position == baseaddr[color]) nextone =  1 + baseadding[color];
    else if (position == turnaroundpoint[color]) nextone = position + turnaroundadding[color]+1;
    else if (position == flybase2[color] && nextposition == flyend[color]) nextone = flyend[color];
    else if (position == 52) nextone=1;
    else if (state2) nextone--;
    else nextone++;
    if (nextone==endpoint[color]) state2=1;
    if(position!=nextone){
        speedx = 0.5f*(coordinatex[nextone]-currentx);
        speedy = 0.5f*(coordinatey[nextone]-currenty);
    }
}

void chess::calculatingnext(int forward){
    jumposition = -2;
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
             jumposition = forward+baseadding[color];
            nextposition =  forward + 4 + baseadding[color];
         }
         else{
            nextposition =  forward + baseadding[color];
         }
         state = 2;
    }
    //normal
    else if (state==2){
        if(color==3 && (position + forward == 53)){
            jumposition = flybase1[color];
            nextposition = flyend[color];
            counter++;
        }
        else if(position + forward == flybase1[color]){
            jumposition = flybase1[color];
            nextposition = flyend[color];
            counter++;
            if(color == 2) passstart = true;
        }
        else if(color==3 && (position + forward == 57)){
            nextposition = flyend[color];
            counter++;
        }
        else if(position + forward == flybase2[color]){
            nextposition = flyend[color];
            counter++;
            if(color == 2) passstart = true;
        }
        else if(((position + forward - colorjump[color]) % 4 == 0) && (position + forward!=turnaroundpoint[color])){
            nextposition = position + forward + 4;
            jumposition = position+forward;
        }
        else{
            nextposition = position + forward;
        }

        if((nextposition >= turnaroundpoint[color]) && passstart == true){
            if(nextposition != turnaroundpoint[color]){
                if(((position + forward - colorjump[color]) % 4 == 0) && (position + forward < turnaroundpoint[color])){
                    nextposition = position + forward + 4 + turnaroundadding[color];
                    jumposition = position + forward;
                }
                else{
                    nextposition = position + forward + turnaroundadding[color];
                }
            }
            state = 3;
        }
        if(color != 0 && nextposition > 52 && state!=3){
            nextposition -= flyminus;
            passstart = true;
        }
        if (jumposition > 52) jumposition -= flyminus;
    }
    //In protection
    else if(state == 3){
        if(position == turnaroundpoint[color]){
            nextposition = position + turnaroundadding[color] + forward;
            if(nextposition == endpoint[color]){
                counter++;
                state = 4;
            }
        }
        else{
            if(position + forward == endpoint[color]){
                nextposition = endpoint[color];
                counter++;
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
    if (jumposition!=-2) counter++;
    if(position!=nextposition) calculatingnextone();
    else{
        updatetimer->stop();
    }
}

void chess::move(){
    if (counter<=0) {
        state2 = 0;
        bool stop2 = updatetimer->isActive();
        if (stop2) updatetimer->stop();
        return;
    }
    if (position!=nextone && t<2) {
        currentx += speedx;
        currenty += speedy;
        t++;
    }
    else {
        t=0;
        counter--;
        position = nextone;
        if (nextone == nextposition) {
            if (position==endpoint[color]) {
                nextposition = -1;
                nextone = -1;
                Qtcolor[color][number] = QColor(249,58,249);
                speedx = 0.5f*(startx[color][number]-currentx);
                speedy = 0.5f*(starty[color][number]-currenty);
            }
            else {
                state2 = 0;
                if (backtimer->isActive()) {
                    backtimer->stop();
                    height2 = height;
                    boom = 0;
                    state = 0;
                    if (!color) passstart = false;
                    if (finish) {
                        endwindow *end = new endwindow(color, username[color]);
                        end->show();
                    }
                }
                else {
                    updatetimer->stop();
                    height2 = height;
                    if (boom) backtimer->start();
                    else if (finish){
                        endwindow *end = new endwindow(color, username[color]);
                        end->show();
                    }
                }
            }
        }
        else calculatingnextone();
    }
}

void chess::draw(){
    glBegin(GL_POLYGON);
    qglColor(Qtcolor[color][number]);
    for (float radian=0.0; radian<2*3.14159; radian+=0.05)
    {
        glTexCoord2f(currentx-0.2f+0.5f*cos(radian), currenty-0.2f+0.5f*sin(radian));
        glVertex3f(currentx+0.5f*cos(radian), currenty+0.5f*sin(radian),height2+0.3f);
    }
    glEnd();

    glBegin(GL_QUADS);
    qglColor(QColor(227,227,227));
    for (float radian=0.0; radian<2*3.14159; radian+=0.05)
    {
        glVertex3f(currentx+0.5f*cos(radian), currenty+0.5f*sin(radian),height2);
        glVertex3f(currentx+0.5f*cos(radian+0.05), currenty+0.5f*sin(radian+0.05),height2);
        glVertex3f(currentx+0.5f*cos(radian+0.05), currenty+0.5f*sin(radian+0.05),height2+0.3f);
        glVertex3f(currentx+0.5f*cos(radian), currenty+0.5f*sin(radian),height2+0.3f);
    }
    glEnd();
}
