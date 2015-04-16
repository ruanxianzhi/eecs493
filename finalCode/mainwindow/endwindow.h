#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QDialog>

namespace Ui {
class endwindow;
}

class endwindow : public QDialog
{
    Q_OBJECT

public:
    explicit endwindow(int wincolor, QString winnername, QWidget *parent = 0);
    ~endwindow();

private slots:
    void on_pushButton_2_clicked();



private:
    Ui::endwindow *ui;
};

#endif // ENDWINDOW_H
