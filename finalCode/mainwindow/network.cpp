#include "network.h"
#include <QtWidgets>
#include "stdlib.h"
#include <ctime>

netWork::netWork(waitingroom *wr, QWidget *parent) :
    QWidget(parent)
{
    pixmap[0] = QPixmap(":/image/1.png").scaled(75,75,Qt::KeepAspectRatio);
    pixmap[1] = QPixmap(":/image/2.png").scaled(75,75,Qt::KeepAspectRatio);
    pixmap[2] = QPixmap(":/image/3.png").scaled(75,75,Qt::KeepAspectRatio);
    pixmap[3] = QPixmap(":/image/4.png").scaled(75,75,Qt::KeepAspectRatio);
    pixmap[4] = QPixmap(":/image/5.png").scaled(75,75,Qt::KeepAspectRatio);
    pixmap[5] = QPixmap(":/image/6.png").scaled(75,75,Qt::KeepAspectRatio);
    srand((unsigned)time(0));
    waitingroomPtr = wr;
    udpSocket = new QUdpSocket(this);
    port = 23333;
    reduser = "";
    blueuser = "";
    greenuser = "";
    yellowuser = "";
    mycolor = "";
    isLeft = false;
    turn = "red";
    bw = NULL;
    udpSocket->bind(port,QUdpSocket::ShareAddress
                                    | QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    sendMessage(NewParticipant);
    connect(waitingroomPtr->blue,SIGNAL(clicked()),this,SLOT(choosebluecolor()));
    connect(waitingroomPtr->red,SIGNAL(clicked()),this,SLOT(chooseredcolor()));
    connect(waitingroomPtr->yellow,SIGNAL(clicked()),this,SLOT(chooseyellowcolor()));
    connect(waitingroomPtr->green,SIGNAL(clicked()),this,SLOT(choosegreencolor()));
    connect(waitingroomPtr->leave,SIGNAL(clicked()),this,SLOT(leave()));
    connect(waitingroomPtr->play,SIGNAL(clicked()),this,SLOT(play()));
    waitingroomPtr->play->setEnabled(false);
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
        int randomNumber;
        in >>randomNumber;
        if (checkUDP[randomNumber]!=0)
            continue;
        checkUDP[randomNumber] = 1;
        in>> messageType;
        QString userName,localHostName,ipAddress,colortype;
        int rstep,rselectedButton;
        switch(messageType)
        {
            case Start:
                {
                    in>>userName;
                    if (userName==yellowuser)
                        turn = "yellow";
                    else if (userName==greenuser)
                        turn = "green";
                    else if (userName==blueuser)
                        turn = "blue";
                    gameStart();
                    QByteArray data;
                    QDataStream out(&data,QIODevice::WriteOnly);
                    out<<randomNumber <<messageType<<userName;
                    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
                    QMutex mut;
                    mut.lock();
                    mut.tryLock(50+rand()%100);
                    mut.unlock();
                    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
                    break;
                }
            case NewParticipant:
                {
                    in >>userName;
                    newParticipant(userName,localHostName,ipAddress);

                    break;
                }
            case ParticipantLeft:
                {
                    in >>userName;
                    participantLeft(userName);
                    break;
                }
            case Choosecolor:{
                in >> userName>>colortype;
                if (colortype == "red"&&reduser==""){
                    reduser = userName;
                 }
                 else if (colortype == "blue"&&blueuser==""){
                    blueuser = userName;
                }
                 else if (colortype == "green"&&greenuser=="")
                    greenuser = userName;
                 else if (colortype == "yellow"&&yellowuser=="")
                    yellowuser = userName;
                 else break;
                 waitingroomPtr->updatelabel(userName,colortype);
                 break;
            }
            case PlayerLeft:{
                if (!bw)
                    return;
                in >> userName;
                QString color="";
                if (userName==reduser){
                    reduser = "";
                    color = "red";
                }
                else if (userName==yellowuser){
                    yellowuser = "";
                    color = "yellow";
                }
                else if (userName==greenuser){
                    greenuser = "";
                    color = "green";
                }
                else if (userName==blueuser){
                    blueuser = "";
                    color = "blue";
                }
                if (color == turn){
                    QString name = "";
                    while (name==""){
                        if (turn == "red"){
                            name = yellowuser;
                            turn = "yellow";
                        }
                        else if (turn == "yellow"){
                            name = greenuser;
                            turn = "green";
                        }
                        else if (turn == "green"){
                            name = blueuser;
                            turn = "blue";
                        }
                        else if (turn == "blue"){
                            name = reduser;
                            turn = "red";
                        }
                    }
                }
                if (turn=="red")
                    bw->changeturn(0);
                else if (turn=="yellow")
                    bw->changeturn(1);
                else if (turn=="green")
                    bw->changeturn(2);
                else if (turn=="blue")
                    bw->changeturn(3);
                QByteArray data;
                QDataStream out(&data,QIODevice::WriteOnly);
                out<<randomNumber <<messageType<<userName;
                udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
                QMutex mut;
                mut.lock();
                mut.tryLock(50+rand()%100);
                mut.unlock();
                udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
                if (bw){
                    for (int i=0; i<5; i++){
                        bw->button[i]->setEnabled(false);
                    }
                    if (turn==mycolor){
                        bw->button[4]->setEnabled(true);
                    }
                }
                break;
            }
            case Move:{
            QString tmp;
                in >> userName>>colortype>>rselectedButton>>rstep>>tmp;
                turn = tmp;
                if (turn=="red")
                    bw->changeturn(0);
                else if (turn=="yellow")
                    bw->changeturn(1);
                else if (turn=="green")
                    bw->changeturn(2);
                else
                    bw->changeturn(3);

                QByteArray data;
                QDataStream out(&data,QIODevice::WriteOnly);
                out<<randomNumber <<messageType << getUserName()<<colortype<<rselectedButton<<rstep<<tmp;
                udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
                bw->dice->setPixmap(pixmap[rstep-1]);

                if (rselectedButton!=5){
                    int colorNum = 0;
                    if (colortype=="red")
                        colorNum = 0;
                    else if (colortype=="yellow")
                        colorNum = 1;
                    else if (colortype=="green")
                        colorNum = 2;
                    else
                        colorNum = 3;
                    bw->in->update(colorNum,rstep,rselectedButton);
                }
                if (rstep!=6){
                    QString user = "";
                    while (user==""){
                        if (turn=="red"){
                            turn = "yellow";
                            user = yellowuser;
                        }
                        else if (turn=="yellow"){
                            turn = "green";
                            user = greenuser;
                        }
                        else if (turn=="green"){
                            turn = "blue";
                            user = blueuser;
                        }
                        else {
                            turn = "red";
                            user = reduser;
                        }
                    }
                }
                if (turn=="red")
                    bw->changeturn(0);
                else if (turn=="yellow")
                    bw->changeturn(1);
                else if (turn=="green")
                    bw->changeturn(2);
                else
                    bw->changeturn(3);
                udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
                QMutex mut;
                mut.lock();
                mut.tryLock(50+rand()%100);
                mut.unlock();
                udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
                for (int i=0; i<5; i++){
                    bw->button[i]->setEnabled(false);
                }
                if (turn==mycolor){
                    bw->button[4]->setEnabled(true);
                }
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
        if (mycolor!=""){
            sendMessage(Choosecolor,mycolor);
        }
    }
}

void netWork::participantLeft(QString userName)
{
    if (waitingroomPtr->tw->findItems(userName,Qt::MatchExactly).isEmpty())
            return;
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

void netWork::sendMessage(MessageType type, QString colortype)  //send message
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    int x = rand();
    while (checkUDP[x]!=0) x = rand();
    out<<x <<type << getUserName();// << localHostName;

    switch(type)
    {
        case ParticipantLeft:
            {
                break;
            }
        case NewParticipant:
            {
                break;
            }

        case Start :
            {
               break;
            }
        case Choosecolor :
            {
                out << colortype;
                break;
            }
        case Move:
            {
                out<<mycolor<<selectedButton<<step<<turn;
                break;
            }
        case PlayerLeft:
            {
                break;
            }
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
    QMutex mut;
    mut.lock();
    mut.tryLock(50+rand()%100);
    mut.unlock();
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
    mut.lock();
    mut.tryLock(50+rand()%100);
    mut.unlock();
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
    mut.lock();
    mut.tryLock(50+rand()%100);
    mut.unlock();
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
    return NULL;
}

void netWork::chooseredcolor(){
    if (reduser == "" && mycolor == ""){
            sendMessage(Choosecolor,"red");
            mycolor = "red";
            waitingroomPtr->play->setEnabled(true);
     }
}

void netWork::choosebluecolor(){
    if(blueuser == "" && mycolor == ""){
            sendMessage(Choosecolor,"blue");
            mycolor = "blue";
            waitingroomPtr->play->setEnabled(true);
    }

}
void netWork::choosegreencolor(){
    if (greenuser == "" && mycolor == ""){
             sendMessage(Choosecolor,"green");
             mycolor = "green";
             waitingroomPtr->play->setEnabled(true);
    }

}
void netWork::chooseyellowcolor(){
    if (yellowuser == "" && mycolor == ""){
            sendMessage(Choosecolor,"yellow");
            mycolor = "yellow";
            waitingroomPtr->play->setEnabled(true);
    }

}
void netWork::leave(){
    mycolor = "";
    sendMessage(ParticipantLeft);
    waitingroomPtr->close();
}

void netWork::play(){
    sendMessage(Start);
}

void netWork::joinAgain(){
    isLeft = false;
    sendMessage(NewParticipant);
}

void netWork::gameStart(){
    if(!bw){
        bw = new boardWindow(reduser,yellowuser,greenuser,blueuser);
        for (int i=0; i<5; i++){
            bw->button[i]->setEnabled(false);
            if(i!=4){
                QPixmap pixmap(":/image/plane.png");
                QIcon icon(pixmap);
                bw->button[i]->setIcon(icon);
                bw->button[i]->setIconSize(QSize(65,65));
            }
        }
        bw->dice->setPixmap(pixmap[0]);
        if (mycolor==turn)
            bw->button[4]->setEnabled(true);
        if (mycolor=="red"){
            bw->in->rotationZ = -90;
            bw->splitter->setStyleSheet("QSplitter {background: #FADFDC}");
            bw->button[0]->setStyleSheet("background-color:rgb(201,2,2);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[1]->setStyleSheet("background-color:rgb(247,07,143);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[2]->setStyleSheet("background-color:rgb(240,117,144);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[3]->setStyleSheet("background-color:rgb(242,167,210);border: 2px solid #8f8f91; border-radius: 20px");}
        else if (mycolor=="yellow"){
            bw->splitter->setStyleSheet("QSplitter {background: #FCFAD4}");
            bw->button[0]->setStyleSheet("background-color:rgb(255,191,00);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[1]->setStyleSheet("background-color:rgb(255,225,00);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[2]->setStyleSheet("background-color:rgb(245,229,130);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[3]->setStyleSheet("background-color:rgb(222,212,100);border: 2px solid #8f8f91; border-radius: 20px");}
        else if (mycolor=="green"){
            bw->in->rotationZ = 90;
            bw->splitter->setStyleSheet("QSplitter {background: #D5FCAE}");
            bw->button[0]->setStyleSheet("background-color: rgb(70,222,40);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[1]->setStyleSheet("background-color: rgb(6,196,73);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[2]->setStyleSheet("background-color: rgb(169,247,153);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[3]->setStyleSheet("background-color: rgb(172,242,197);border: 2px solid #8f8f91; border-radius: 20px");}
        else if (mycolor=="blue"){
            bw->in->rotationZ = 180;
            bw->splitter->setStyleSheet("QSplitter {background: #CAE6FC}");
            bw->button[0]->setStyleSheet("background-color: rgb(0,33,250);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[1]->setStyleSheet("background-color: rgb(144,158,245);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[2]->setStyleSheet("background-color: rgb(0,196,250);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[3]->setStyleSheet("background-color: rgb(196,228,245);border: 2px solid #8f8f91; border-radius: 20px");}
        else{
            bw->splitter->setStyleSheet("QSplitter {background: #EDECEB}");
            bw->button[0]->setStyleSheet("background-color: rgb(235,236,237);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[1]->setStyleSheet("background-color: rgb(235,236,237);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[2]->setStyleSheet("background-color: rgb(235,236,237);border: 2px solid #8f8f91; border-radius: 20px");
            bw->button[3]->setStyleSheet("background-color: rgb(235,236,237);border: 2px solid #8f8f91; border-radius: 20px");}
        connect(bw->button[0],SIGNAL(clicked()),this,SLOT(flignt0_clicked()));
        connect(bw->button[1],SIGNAL(clicked()),this,SLOT(flignt1_clicked()));
        connect(bw->button[2],SIGNAL(clicked()),this,SLOT(flignt2_clicked()));
        connect(bw->button[3],SIGNAL(clicked()),this,SLOT(flignt3_clicked()));
        connect(bw->button[4],SIGNAL(clicked()),this,SLOT(roll_clicked()));
    }
    bw->show();
}

void netWork::flignt0_clicked(){
    selectedButton = 0;
    sendMessage(Move);
}

void netWork::flignt1_clicked(){
    selectedButton = 1;
    sendMessage(Move);
}

void netWork::flignt2_clicked(){
    selectedButton = 2;
    sendMessage(Move);
}

void netWork::flignt3_clicked(){
    selectedButton = 3;
    sendMessage(Move);
}

void netWork::roll_clicked(){
    bw->button[4]->setEnabled(false);
    step = rand() % 6 +1;
    bw->dice->setPixmap(pixmap[step-1]);
    int colorNum;
    if (mycolor=="red")
        colorNum = 0;
    else if (mycolor=="yellow")
        colorNum = 1;
    else if (mycolor=="green")
        colorNum = 2;
    else
        colorNum = 3;
    bool check = false;
    if (step!=6){
        if (bw->in->newgame->allparty[colorNum]->ownchess[0]->state!=0&&bw->in->newgame->allparty[colorNum]->ownchess[0]->state!=4){
            bw->button[0]->setEnabled(true);
            QPixmap pixmap(":/image/plane.png");
            QIcon icon(pixmap);
            bw->button[0]->setIcon(icon);
            bw->button[0]->setIconSize(QSize(65,65));
            check = true;
        }
        if (bw->in->newgame->allparty[colorNum]->ownchess[1]->state!=0&&bw->in->newgame->allparty[colorNum]->ownchess[1]->state!=4){
            bw->button[1]->setEnabled(true);
            QPixmap pixmap(":/image/plane.png");
            QIcon icon(pixmap);
            bw->button[1]->setIcon(icon);
            bw->button[1]->setIconSize(QSize(65,65));
            check = true;
        }
        if (bw->in->newgame->allparty[colorNum]->ownchess[2]->state!=0&&bw->in->newgame->allparty[colorNum]->ownchess[2]->state!=4){
            bw->button[2]->setEnabled(true);
            QPixmap pixmap(":/image/plane.png");
            QIcon icon(pixmap);
            bw->button[2]->setIcon(icon);
            bw->button[2]->setIconSize(QSize(65,65));
            check = true;
        }
        if (bw->in->newgame->allparty[colorNum]->ownchess[3]->state!=0&&bw->in->newgame->allparty[colorNum]->ownchess[3]->state!=4){
            bw->button[3]->setEnabled(true);
            QPixmap pixmap(":/image/plane.png");
            QIcon icon(pixmap);
            bw->button[3]->setIcon(icon);
            bw->button[3]->setIconSize(QSize(65,65));
            check = true;
        }if(bw->in->newgame->allparty[colorNum]->ownchess[0]->state==4){
            QPixmap pixmap(":/image/huangguan.png");
            QIcon icon(pixmap);
            bw->button[0]->setIcon(icon);
            bw->button[0]->setIconSize(QSize(65,65));
        }
        if(bw->in->newgame->allparty[colorNum]->ownchess[1]->state==4){
            QPixmap pixmap(":/image/huangguan.png");
            QIcon icon(pixmap);
            bw->button[1]->setIcon(icon);
            bw->button[1]->setIconSize(QSize(65,65));
        }
        if(bw->in->newgame->allparty[colorNum]->ownchess[2]->state==4){
            QPixmap pixmap(":/image/huangguan.png");
            QIcon icon(pixmap);
            bw->button[2]->setIcon(icon);
            bw->button[2]->setIconSize(QSize(65,65));
        }
        if(bw->in->newgame->allparty[colorNum]->ownchess[3]->state==4){
            QPixmap pixmap(":/image/huangguan.png");
            QIcon icon(pixmap);
            bw->button[3]->setIcon(icon);
            bw->button[3]->setIconSize(QSize(65,65));
        }
        if (!check){
            selectedButton = 5;
            sendMessage(Move);
        }
    }
    else {
        for (int i=0; i<4; i++){
            if (bw->in->newgame->allparty[colorNum]->ownchess[i]->state!=4){
                bw->button[i]->setEnabled(true);
                QPixmap pixmap(":/image/plane.png");
                QIcon icon(pixmap);
                bw->button[i]->setIcon(icon);
                bw->button[i]->setIconSize(QSize(65,65));
            }
        }
    }
}


