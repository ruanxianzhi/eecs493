#ifndef SET_H
#define SET_H

#include <QDialog>
#include <QMediaPlayer>
#include <QSlider>

namespace Ui {
class set;
}

class set : public QDialog
{
    Q_OBJECT

public:
    explicit set(QMediaPlayer *input, QWidget *parent = 0);
    ~set();

    QPushButton *ok;
    QPushButton *cancel;
    QMediaPlayer *play;
    QFont fnt;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
private:
    Ui::set *ui;
};

#endif // SET_H
