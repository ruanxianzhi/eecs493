#ifndef RULES_H
#define RULES_H

#include <QDialog>
#include <QToolButton>
#include <QLabel>

namespace Ui {
class rules;
}

class rules : public QDialog
{
    Q_OBJECT

public:
    explicit rules(QWidget *parent = 0);
    ~rules();
    QToolButton *front;
    QToolButton *back;

    QLabel *image1;
    QLabel *image2;
    QLabel *text1;
    QLabel *text2;
    int counter;
    QFont fnt;

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();


private:
    Ui::rules *ui;
};

#endif // RULES_H
