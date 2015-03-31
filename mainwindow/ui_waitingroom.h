/********************************************************************************
** Form generated from reading UI file 'waitingroom.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_waitingroom
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QTableWidget *tableWidget;

    void setupUi(QDialog *waitingroom)
    {
        if (waitingroom->objectName().isEmpty())
            waitingroom->setObjectName(QStringLiteral("waitingroom"));
        waitingroom->resize(847, 541);
        pushButton = new QPushButton(waitingroom);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 450, 181, 61));
        pushButton->setStyleSheet(QLatin1String("border-color: #FFFF33;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6CC9EB, stop: 1 #0d5ca6); \n"
"font: 36pt \"HanziPen SC\";\n"
"border-width: 5px;\n"
"border-radius: 15px;"));
        pushButton_2 = new QPushButton(waitingroom);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 450, 181, 61));
        pushButton_2->setStyleSheet(QLatin1String("border-color: #FFFF33;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6CC9EB, stop: 1 #0d5ca6); \n"
"font: 36pt \"HanziPen SC\";\n"
"border-width: 5px;\n"
"border-radius: 15px;"));
        tableView = new QTableView(waitingroom);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(150, 60, 361, 311));
        tableView->setStyleSheet(QStringLiteral("background-color: transparent;"));
        tableWidget = new QTableWidget(waitingroom);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(153, 242, 226));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(590, 30, 221, 351));
        tableWidget->setStyleSheet(QStringLiteral("background-color: transparent;"));

        retranslateUi(waitingroom);

        QMetaObject::connectSlotsByName(waitingroom);
    } // setupUi

    void retranslateUi(QDialog *waitingroom)
    {
        waitingroom->setWindowTitle(QApplication::translate("waitingroom", "Dialog", 0));
        pushButton->setText(QApplication::translate("waitingroom", "Leave", 0));
        pushButton_2->setText(QApplication::translate("waitingroom", "Ready", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("waitingroom", "User name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("waitingroom", "Host name", 0));
    } // retranslateUi

};

namespace Ui {
    class waitingroom: public Ui_waitingroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGROOM_H
