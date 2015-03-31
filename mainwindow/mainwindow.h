#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <waitingroom.h>
#include "network.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    netWork *n;


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    waitingroom *waitui;

};

#endif // MAINWINDOW_H
