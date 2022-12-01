/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *filename0;
    QLabel *filename1;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit1;
    QTextEdit *textEdit2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCompare;
    QPushButton *btnequal;
    QPushButton *btnEqual;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(895, 496);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");

        gridLayout->addWidget(widget, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        filename0 = new QLabel(centralwidget);
        filename0->setObjectName("filename0");

        horizontalLayout_3->addWidget(filename0);

        filename1 = new QLabel(centralwidget);
        filename1->setObjectName("filename1");

        horizontalLayout_3->addWidget(filename1);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        textEdit1 = new QTextEdit(centralwidget);
        textEdit1->setObjectName("textEdit1");
        QFont font;
        font.setPointSize(11);
        textEdit1->setFont(font);

        horizontalLayout->addWidget(textEdit1);

        textEdit2 = new QTextEdit(centralwidget);
        textEdit2->setObjectName("textEdit2");
        textEdit2->setFont(font);

        horizontalLayout->addWidget(textEdit2);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnCompare = new QPushButton(centralwidget);
        btnCompare->setObjectName("btnCompare");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnCompare->sizePolicy().hasHeightForWidth());
        btnCompare->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        btnCompare->setFont(font1);

        horizontalLayout_2->addWidget(btnCompare);

        btnequal = new QPushButton(centralwidget);
        btnequal->setObjectName("btnequal");
        sizePolicy.setHeightForWidth(btnequal->sizePolicy().hasHeightForWidth());
        btnequal->setSizePolicy(sizePolicy);
        btnequal->setFont(font1);

        horizontalLayout_2->addWidget(btnequal);

        btnEqual = new QPushButton(centralwidget);
        btnEqual->setObjectName("btnEqual");
        sizePolicy.setHeightForWidth(btnEqual->sizePolicy().hasHeightForWidth());
        btnEqual->setSizePolicy(sizePolicy);
        btnEqual->setFont(font1);

        horizontalLayout_2->addWidget(btnEqual);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 6);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 895, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        filename0->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        filename1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        textEdit1->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\214\211\344\270\213\347\255\211\344\273\267\346\210\226\350\200\205\344\270\215\347\255\211\344\273\267\345\274\200\345\247\213\347\255\211\344\273\267\347\241\256\350\256\244</p></body></html>", nullptr));
        textEdit2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\214\211\344\270\213\347\255\211\344\273\267\346\210\226\350\200\205\344\270\215\347\255\211\344\273\267\345\274\200\345\247\213\347\255\211\344\273\267\347\241\256\350\256\244</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\270\215\345\220\214\344\271\213\345\244\204\345\260\206\351\253\230\344\272\256"
                        "\346\230\276\347\244\272</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnCompare->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        btnequal->setText(QCoreApplication::translate("MainWindow", "Equal", nullptr));
        btnEqual->setText(QCoreApplication::translate("MainWindow", "Inequal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
