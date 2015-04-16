#ifndef QUIT_H
#define QUIT_H

#include <QDialog>

namespace Ui {
class quit;
}

class quit : public QDialog
{
    Q_OBJECT

public:
    explicit quit(QWidget *parent = 0);
    ~quit();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::quit *ui;
};

#endif // QUIT_H
