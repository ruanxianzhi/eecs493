#ifndef NETWORK_H
#define NETWORK_H

#include <QWidget>
#include <QtNetwork>
#include <QtGui>
#include "waitingroom.h"
namespace Ui {
    class Widget;
}

enum MessageType{Message,NewParticipant,ParticipantLeft};

class netWork : public QWidget
{
    Q_OBJECT

public:
    explicit netWork(waitingroom *wr, QWidget *parent = 0);
    ~netWork();
    QString getUserName();

protected:
    void sendMessage(MessageType type,QString serverAddress="");
    void newParticipant(QString userName,QString localHostName,QString ipAddress);
    void participantLeft(QString userName,QString localHostName,QString time);

private:
    QUdpSocket *udpSocket;
    qint16 port;
    QString getIP();
    waitingroom *waitingroomPtr;

private slots:
    void processPendingDatagrams();

};

#endif // NETWORK_H
