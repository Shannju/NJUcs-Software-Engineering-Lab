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
    string filename;
public:
    explicit ufs(const string &filename) ;
    void setParent(ufs * parent);
    string getName(){return filename;}
    bool isRoot(){return p == this;}
    ufs* getParent ();
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
    void write();


private:
    vector<ufs*> ufset;
    output o;
    input i;
    fPair fp;
    Ui::MainWindow *ui;
    int find(string name);
    QColor m_txtBox1Color, m_txtBox2Color;


private slots:
    void ClearAll() ;

    void on_btnCompare_released();

    void on_btnequal_released();
    void on_btnEqual_released();
};
#endif // MAINWINDOW_H
