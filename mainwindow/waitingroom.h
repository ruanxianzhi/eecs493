#ifndef WAITINGROOM_H
#define WAITINGROOM_H

#include <QDialog>

namespace Ui {
class waitingroom;
}

class waitingroom : public QDialog
{
    Q_OBJECT

public:
    explicit waitingroom(QWidget *parent = 0);
    ~waitingroom();
    Ui::waitingroom *ui;
    bool updateUser(QString userName,QString localHostName,QString ipAddress);
    void updatelabel(QString userName,QString color);
    QPushButton *red;
    QPushButton *blue;
    QPushButton *green;
    QPushButton *yellow;
    QPushButton *leave;
    QFont fnt;

};

#endif // WAITINGROOM_H
