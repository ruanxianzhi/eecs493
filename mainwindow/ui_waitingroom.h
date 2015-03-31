/********************************************************************************
** Form generated from reading UI file 'waitingroom.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGROOM_H
#define UI_WAITINGROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_waitingroom
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLabel *red;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *waitingroom)
    {
        if (waitingroom->objectName().isEmpty())
            waitingroom->setObjectName(QStringLiteral("waitingroom"));
        waitingroom->resize(847, 541);
        pushButton = new QPushButton(waitingroom);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 450, 181, 61));
        pushButton->setStyleSheet(QLatin1String("border-color: #FFFF33;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6CC9EB, stop: 1 #0d5ca6); \n"
"font: 36pt \"HanziPen SC\";\n"
"border-width: 5px;\n"
"border-radius: 15px;"));
        tableWidget = new QTableWidget(waitingroom);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QFont font;
        font.setFamily(QStringLiteral("HanziPen SC"));
        font.setPointSize(36);
        font.setBold(false);
        font.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setBackground(QColor(102, 204, 255, 23));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(520, 40, 231, 351));
        tableWidget->setStyleSheet(QStringLiteral("background-color: QColor(189,202,242, 054);"));
        red = new QLabel(waitingroom);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(100, 180, 141, 31));
        red->setStyleSheet(QStringLiteral("font: 24pt \"HanziPen SC\";"));
        red->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(waitingroom);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 180, 141, 31));
        label_2->setStyleSheet(QStringLiteral("font: 24pt \"HanziPen SC\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(waitingroom);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 380, 141, 31));
        label_3->setStyleSheet(QStringLiteral("font: 24pt \"HanziPen SC\";"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(waitingroom);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 380, 141, 31));
        label_4->setStyleSheet(QStringLiteral("font: 24pt \"HanziPen SC\";"));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(waitingroom);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 50, 131, 121));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #F28B77, stop: 1 #D64E3C); border:none; border-color:#F28B77;"));
        pushButton_3 = new QPushButton(waitingroom);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 50, 131, 121));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #9BCCEB, stop: 1 #086BD4); border:none;"));
        pushButton_4 = new QPushButton(waitingroom);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 250, 131, 121));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #7BE87D, stop: 1 #16B819); border:none;"));
        pushButton_5 = new QPushButton(waitingroom);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(340, 250, 131, 121));
        pushButton_5->setStyleSheet(QStringLiteral("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #F2F1B1, stop: 1 #FFFC4D); border:none;"));
        pushButton->raise();
        tableWidget->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        red->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();

        retranslateUi(waitingroom);

        QMetaObject::connectSlotsByName(waitingroom);
    } // setupUi

    void retranslateUi(QDialog *waitingroom)
    {
        waitingroom->setWindowTitle(QApplication::translate("waitingroom", "Dialog", 0));
        pushButton->setText(QApplication::translate("waitingroom", "Leave", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("waitingroom", "User name", 0));
        red->setText(QApplication::translate("waitingroom", "No Player", 0));
        label_2->setText(QApplication::translate("waitingroom", "No Player", 0));
        label_3->setText(QApplication::translate("waitingroom", "No Player", 0));
        label_4->setText(QApplication::translate("waitingroom", "No Player", 0));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class waitingroom: public Ui_waitingroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGROOM_H
