//---------------------------------------------------------->
//  MainWindow.h file.
//  Author     : Jayakrishnan P.
//  Last Edited: 14/10/2022
//---------------------------------------------------------->
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstring>
#include <fstream>
#include "qdebug.h"
#include <iostream>
#include <vector>
#include "output.h"
#include "input.h"
using namespace std;
#define enable_debug
#ifdef enable_debug
#define debug(s) {cerr<< s<<'/n';}
#else
#define debug(...){}
#endif


class ufs{
    ufs * p;
    string content;
    string filename;
public:
    explicit ufs(const string &filename) ;
    void setParent(ufs * parent);
    bool isRoot(){return p == this;}
    ufs* getParent (){return p;}
    string getContent(){return content;}
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    vector<ufs> ufset;
    output o;
    input i;
    Ui::MainWindow *ui;

    QColor m_txtBox1Color, m_txtBox2Color;
    QColor GetColor(QString);

private slots:
    void on_btnCompare_released();

};
#endif // MAINWINDOW_H
