#ifndef NETWORK_H
#define NETWORK_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>
#include "waitingroom.h"
#include "boardwindow.h"
namespace Ui {
    class Widget;
}

enum MessageType{Message,NewParticipant,ParticipantLeft,Choosecolor};

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

protected:
    void sendMessage(MessageType type,QString colortype = "");
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

};

#endif // NETWORK_H
