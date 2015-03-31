#include "network.h"
#include <QtWidgets>

netWork::netWork(waitingroom *wr, QWidget *parent) :
    QWidget(parent)
{
    waitingroomPtr = wr;
    udpSocket = new QUdpSocket(this);
    port = 45450;
    udpSocket->bind(port,QUdpSocket::ShareAddress
                                    | QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    sendMessage(NewParticipant);
}

void netWork::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        int messageType;
        in >> messageType;
        QString userName,localHostName,ipAddress,message;
        switch(messageType)
        {
            case Message:
                {
                    /*in >>userName >>localHostName >>ipAddress >>message;
                    ui->textBrowser->setTextColor(Qt::blue);
                    ui->textBrowser->setCurrentFont(QFont("Times New Roman",12));
                    ui->textBrowser->append("[ " +userName+" ] "+ time);
                    ui->textBrowser->append(message);*/
                    break;
                }
            case NewParticipant:
                {
                    in >>userName >>localHostName >>ipAddress;
                    newParticipant(userName,localHostName,ipAddress);

                    break;
                }
            case ParticipantLeft:
                {
                    in >>userName >>localHostName;
                    //participantLeft(userName,localHostName,time);
                    break;
                }
        }
    }
}

void netWork::newParticipant(QString userName,QString localHostName,QString ipAddress)
{
    bool bb = waitingroomPtr->updateUser(userName, localHostName, ipAddress);
    if(bb)
    {
        sendMessage(NewParticipant);
    }
}

void netWork::participantLeft(QString userName,QString localHostName,QString time)
{
    /*int rowNum = ui->tableWidget->findItems(localHostName,Qt::MatchExactly).first()->row();
    ui->tableWidget->removeRow(rowNum);
    ui->textBrowser->setTextColor(Qt::gray);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->textBrowser->append(tr("%1 left at %2").arg(userName).arg(time));
    ui->onlineUser->setText(tr("current user: %1").arg(ui->tableWidget->rowCount()));*/
}

netWork::~netWork()
{

}


QString netWork::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list)
    {
       if(address == QHostAddress::LocalHost ) continue;
       if(address.protocol() == QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
       return 0;
}

void netWork::sendMessage(MessageType type, QString serverAddress)  //发送信息
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();
    QString address = getIP();

    out << type << getUserName() << localHostName;


    switch(type)
    {
        case ParticipantLeft:
            {
                break;
            }
        case NewParticipant:
            {
                out << address;
                break;
            }

        case Message :
            {
                /*if(ui->textEdit->toPlainText() == "")
                {
                    QMessageBox::warning(0,tr("warning"),tr("no contents"),QMessageBox::Ok);
                    return;
                }
               out << address << getMessage();
               ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());*/
               break;

            }
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);

}

QString netWork::getUserName()
{
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach (QString string, envVariables)
    {
        int index = environment.indexOf(QRegExp(string));
        if (index != -1)
        {

            QStringList stringList = environment.at(index).split('=');
            if (stringList.size() == 2)
            {
                return stringList.at(1);
                break;
            }
        }
    }
    return false;
}

