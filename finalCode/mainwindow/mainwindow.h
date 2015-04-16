#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <waitingroom.h>
#include <rules.h>
#include <set.h>
#include <quit.h>
#include <QMediaPlaylist>
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
    QMediaPlayer *play;
    QMediaPlaylist *playlist;
    void closeEvent(QCloseEvent *);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    waitingroom *waitui;
    rules *ruleui;
    set *setui;
    quit *quitui;

};

#endif // MAINWINDOW_H
