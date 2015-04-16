#ifndef NETWORK_H
#define NETWORK_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>
#include "waitingroom.h"
#include "boardwindow.h"
#include "chess.h"
#include "widget.h"
#include "QHash"
namespace Ui {
    class Widget;
}

enum MessageType{NewParticipant,ParticipantLeft,Choosecolor, Move,Start,PlayerLeft};

class netWork : public QWidget
{
    Q_OBJECT

public:
    explicit netWork(waitingroom *wr, QWidget *parent = 0);
    ~netWork();
    QString getUserName();
    void joinAgain();
    bool isLeft;
    void tryStart();
    void gameStart();
    boardWindow *bw;
    QString turn;//red yellow green blue
    int step;
    map<int,int> checkUDP;
    int selectedButton;
    QPixmap pixmap[6];


    void sendMessage(MessageType type,QString colortype = "");
protected:
    void newParticipant(QString userName,QString localHostName,QString ipAddress);
    void participantLeft(QString userName);


private:
    QUdpSocket *udpSocket;
    qint16 port;
    QString getIP();
    waitingroom *waitingroomPtr;
    QString reduser;
    QString blueuser;
    QString yellowuser;
    QString greenuser;
    QString mycolor;

private slots:
    void processPendingDatagrams();
    void chooseredcolor();
    void choosebluecolor();
    void choosegreencolor();
    void chooseyellowcolor();
    void leave();
    void play();
    void flignt0_clicked();
    void flignt1_clicked();
    void flignt2_clicked();
    void flignt3_clicked();
    void roll_clicked();
};

#endif // NETWORK_H
