/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *suma;
    QPushButton *division;
    QPushButton *producto;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *op1Decimal;
    QLineEdit *op1Hexa;
    QLineEdit *op1Bin;
    QLineEdit *op2Decimal;
    QLineEdit *op2Bin;
    QLineEdit *op2Hexa;
    QLineEdit *resultadoDecimal;
    QLineEdit *resultadoBin;
    QLineEdit *resultadoHexa;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        suma = new QPushButton(centralwidget);
        suma->setObjectName("suma");
        suma->setGeometry(QRect(190, 190, 80, 18));
        division = new QPushButton(centralwidget);
        division->setObjectName("division");
        division->setGeometry(QRect(520, 190, 80, 18));
        producto = new QPushButton(centralwidget);
        producto->setObjectName("producto");
        producto->setGeometry(QRect(350, 190, 80, 18));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 20, 181, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("ROG Fonts")});
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 20, 211, 20));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(580, 20, 111, 20));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 60, 61, 20));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 100, 101, 20));
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 140, 61, 20));
        label_6->setFont(font);
        op1Decimal = new QLineEdit(centralwidget);
        op1Decimal->setObjectName("op1Decimal");
        op1Decimal->setGeometry(QRect(120, 50, 171, 31));
        op1Hexa = new QLineEdit(centralwidget);
        op1Hexa->setObjectName("op1Hexa");
        op1Hexa->setGeometry(QRect(120, 100, 171, 31));
        op1Bin = new QLineEdit(centralwidget);
        op1Bin->setObjectName("op1Bin");
        op1Bin->setGeometry(QRect(120, 130, 171, 31));
        op2Decimal = new QLineEdit(centralwidget);
        op2Decimal->setObjectName("op2Decimal");
        op2Decimal->setGeometry(QRect(340, 50, 171, 31));
        op2Bin = new QLineEdit(centralwidget);
        op2Bin->setObjectName("op2Bin");
        op2Bin->setGeometry(QRect(340, 130, 171, 31));
        op2Hexa = new QLineEdit(centralwidget);
        op2Hexa->setObjectName("op2Hexa");
        op2Hexa->setGeometry(QRect(340, 90, 171, 31));
        resultadoDecimal = new QLineEdit(centralwidget);
        resultadoDecimal->setObjectName("resultadoDecimal");
        resultadoDecimal->setGeometry(QRect(550, 50, 171, 31));
        resultadoBin = new QLineEdit(centralwidget);
        resultadoBin->setObjectName("resultadoBin");
        resultadoBin->setGeometry(QRect(550, 130, 171, 31));
        resultadoHexa = new QLineEdit(centralwidget);
        resultadoHexa->setObjectName("resultadoHexa");
        resultadoHexa->setGeometry(QRect(550, 90, 171, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        suma->setText(QCoreApplication::translate("MainWindow", "SUMA", nullptr));
        division->setText(QCoreApplication::translate("MainWindow", "DIVISI\303\223N", nullptr));
        producto->setText(QCoreApplication::translate("MainWindow", "PRODUCTO", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "primer operando", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "segundo operando", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "RESULTADO", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "DECIMAL", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "HEXADECIMAL", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "IEEE-754", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
