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
#include <QtGui/QAction>
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
    QAction *actionHighlight_Color;
    QAction *actionClear_All;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit1;
    QTextEdit *textEdit2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCompare;
    QPushButton *btnInequal;
    QPushButton *btnEqual;
    QWidget *widget;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(704, 311);
        actionHighlight_Color = new QAction(MainWindow);
        actionHighlight_Color->setObjectName("actionHighlight_Color");
        actionClear_All = new QAction(MainWindow);
        actionClear_All->setObjectName("actionClear_All");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
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

        btnInequal = new QPushButton(centralwidget);
        btnInequal->setObjectName("btnInequal");
        sizePolicy.setHeightForWidth(btnInequal->sizePolicy().hasHeightForWidth());
        btnInequal->setSizePolicy(sizePolicy);
        btnInequal->setFont(font1);

        horizontalLayout_2->addWidget(btnInequal);

        btnEqual = new QPushButton(centralwidget);
        btnEqual->setObjectName("btnEqual");
        sizePolicy.setHeightForWidth(btnEqual->sizePolicy().hasHeightForWidth());
        btnEqual->setSizePolicy(sizePolicy);
        btnEqual->setFont(font1);

        horizontalLayout_2->addWidget(btnEqual);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 6);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");

        gridLayout->addWidget(widget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 704, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);
        QObject::connect(actionHighlight_Color, SIGNAL(triggered()), MainWindow, SLOT(ShowHighlighterDlg()));
        QObject::connect(actionClear_All, SIGNAL(triggered()), MainWindow, SLOT(ClearAll()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHighlight_Color->setText(QCoreApplication::translate("MainWindow", "Highlight Color", nullptr));
        actionClear_All->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnCompare->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        btnInequal->setText(QCoreApplication::translate("MainWindow", "Equal", nullptr));
        btnEqual->setText(QCoreApplication::translate("MainWindow", "Inequal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
