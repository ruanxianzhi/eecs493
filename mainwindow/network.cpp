#include "network.h"
#include <QtWidgets>

netWork::netWork(waitingroom *wr, QWidget *parent) :
    QWidget(parent)
{
    waitingroomPtr = wr;
    udpSocket = new QUdpSocket(this);
    port = 45450;
    reduser = "";
    blueuser = "";
    greenuser = "";
    yellowuser = "";
    mycolor = "";
    isLeft = false;
    turn = "red";
    udpSocket->bind(port,QUdpSocket::ShareAddress
                                    | QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    sendMessage(NewParticipant);
    connect(waitingroomPtr->blue,SIGNAL(clicked()),this,SLOT(choosebluecolor()));
    connect(waitingroomPtr->red,SIGNAL(clicked()),this,SLOT(chooseredcolor()));
    connect(waitingroomPtr->yellow,SIGNAL(clicked()),this,SLOT(chooseyellowcolor()));
    connect(waitingroomPtr->green,SIGNAL(clicked()),this,SLOT(choosegreencolor()));
    connect(waitingroomPtr->leave,SIGNAL(clicked()),this,SLOT(leave()));

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
        QString userName,localHostName,ipAddress,message,colortype;
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
                    participantLeft(userName);
                    break;
                }
            case Choosecolor:{
                in >> userName>>localHostName>>colortype;
                if (colortype == "red"&&reduser==""){
                    reduser = userName;
                 }
                 else if (colortype == "blue"&&blueuser=="")
                    blueuser = userName;
                 else if (colortype == "green"&&greenuser=="")
                    greenuser = userName;
                 else if (colortype == "yellow"&&yellowuser=="")
                    yellowuser = userName;
                 else break;
                 waitingroomPtr->updatelabel(userName,colortype);
                 tryStart();
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
        if (mycolor!=""){
            sendMessage(Choosecolor,mycolor);
        }
    }
}

void netWork::participantLeft(QString userName)
{
    int rowNum = waitingroomPtr->tw->findItems(userName,Qt::MatchExactly).first()->row();
    if (userName!=getUserName())
        waitingroomPtr->tw->removeRow(rowNum);
    if (yellowuser==userName){
        yellowuser = "";
        waitingroomPtr->updatelabel("No Player","yellow");
    }
    if (reduser==userName){
        reduser = "";
        waitingroomPtr->updatelabel("No Player","red");
    }
    if (blueuser==userName){
        blueuser = "";
        waitingroomPtr->updatelabel("No Player","blue");
    }
    if (greenuser==userName){
        greenuser = "";
        waitingroomPtr->updatelabel("No Player","green");
    }
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

void netWork::sendMessage(MessageType type, QString colortype)  //发送信息
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
        case Choosecolor :
            {
                out << colortype;
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

void netWork::chooseredcolor(){
    //waitingroomPtr->updatelabel(userName,'r');
    if (reduser == "" && mycolor == ""){

            waitingroomPtr->updatelabel(getUserName(),"red");
            sendMessage(Choosecolor,"red");
            mycolor = "red";
            reduser = getUserName();
            tryStart();
     }
}

void netWork::choosebluecolor(){
    //waitingroomPtr->updatelabel(userName,'r');
    if(blueuser == "" && mycolor == ""){
            waitingroomPtr->updatelabel(getUserName(),"blue");
            sendMessage(Choosecolor,"blue");
            mycolor = "blue";
            blueuser = getUserName();
            tryStart();
    }

}
void netWork::choosegreencolor(){
    //waitingroomPtr->updatelabel(userName,'r');
    if (greenuser == "" && mycolor == ""){
             waitingroomPtr->updatelabel(getUserName(),"green");
             sendMessage(Choosecolor,"green");
             greenuser = getUserName();
             mycolor = "green";
             tryStart();
    }

}
void netWork::chooseyellowcolor(){
    //waitingroomPtr->updatelabel(userName,'r');
    if (yellowuser == "" && mycolor == ""){
            waitingroomPtr->updatelabel(getUserName(),"yellow");
            sendMessage(Choosecolor,"yellow");
            yellowuser = getUserName();
            mycolor = "yellow";
            tryStart();
    }

}
void netWork::leave(){
    mycolor = "";
    participantLeft(getUserName());
    sendMessage(ParticipantLeft);
    waitingroomPtr->close();
    //w->show();
}

void netWork::joinAgain(){
    isLeft = false;
    sendMessage(NewParticipant);
}

void netWork::tryStart(){
    if (reduser!=""&&blueuser!=""&&greenuser!="")
            gameStart();
}

void netWork::gameStart(){
    qDebug()<<"Game Start!";
    bw = new boardWindow();
    bw->show();
}
