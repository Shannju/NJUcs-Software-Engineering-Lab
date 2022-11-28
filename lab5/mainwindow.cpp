//---------------------------------------------------------->
//  MainWindow.cpp file.
//  Author     : Jayakrishnan P.
//  Last Edited: 14/10/2022
//---------------------------------------------------------->
#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QMessageBox>
#include  <QList>
#include  <QVector>
#include  <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Text Comparison Tool");
QColor c0,c1;
c0.setRgb(236,188,194);
c1.setRgb(203,121,121);
    m_txtBox1Color =c0 ;
    m_txtBox2Color = c1;


}

MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------------------------------------------->
//  Function Name: MainWindow::OnClickBtnCompare.
//  Return Type  : void.
//  Parameters   : No parameters.
//  Remarks      : Event handler for compare button click.
//---------------------------------------------------------->
//void MainWindow::OnClickBtnCompare()
//{

//}

////---------------------------------------------------------->
////  Function Name: MainWindow::ShowHighlighterDlg.
////  Return Type  : void.
////  Parameters   : None.
////  Remarks      : Creates dialog for highlighting color settings.
////---------------------------------------------------------->
//void MainWindow::ShowHighlighterDlg()
//{
//    HighlightColor* highlighter = new HighlightColor(this);
//    highlighter->show();
//}


////---------------------------------------------------------->
////  Function Name: MainWindow::ClearAll.
////  Return Type  : VOID.
////  Parameters   : None.
////  Remarks      : Clears the text boxes.
////---------------------------------------------------------->
//void MainWindow::ClearAll()
//{
//    ui->textEdit1->clear();
//    ui->textEdit2->clear();
//}




void MainWindow::on_btnCompare_released()
{
    //Taking strings from text boxes.
    QByteArray text1 = (ui->textEdit1->toPlainText()).toUtf8();
    QByteArray text2 = (ui->textEdit2->toPlainText()).toUtf8();

    QList<int> differenceList;


   int larger = 0;
   bool oneIsBig = false;
   bool twoIsBig = false;
    if(text1.length() > text2.length())
    {
        twoIsBig = false;
        oneIsBig = true;
        larger = text1.length();
    }

    if(text1.length() < text2.length())
    {
        twoIsBig = true;
        oneIsBig = false;
        larger = text2.length();
    }

    if(text1.length() == text2.length())
    {
        twoIsBig = false;
        oneIsBig = false;
        larger = text1.length();
    }


    //Filling rest of smaller array with ' '.
    if(oneIsBig == true)
    {
        for(int i = text2.length(); i < text1.length();i++)
        {
            text2.append(' ');
        }
    }
    if(twoIsBig == true)
    {
        for(int i = text1.length(); i < text2.length();i++)
        {
            text1.append(' ');
        }
    }

    ui->textEdit1->setText(text1);
    ui->textEdit2->setText(text2);

    //Finding position indeces of difference between strings.
    for(int i = 0; i < larger; i++)
    {
        if(text1[i] != text2[i])
        {
            differenceList.append(i);
        }
    }

    QTextCursor cursorText1(ui->textEdit1->document());
    QTextCursor cursorText2(ui->textEdit2->document());

    QTextCharFormat backgroundClear, background1, background2;
    backgroundClear.clearBackground();
    background1.setBackground(m_txtBox1Color);
    background2.setBackground(m_txtBox2Color);


    //Text Edit reset.
    cursorText1.setPosition(QTextCursor::Start,QTextCursor::MoveAnchor);
    cursorText1.setPosition(QTextCursor::End,QTextCursor::KeepAnchor);
    cursorText1.setCharFormat(backgroundClear);
    cursorText2.setPosition(QTextCursor::Start,QTextCursor::MoveAnchor);
    cursorText2.setPosition(QTextCursor::End,QTextCursor::KeepAnchor);
    cursorText2.setCharFormat(backgroundClear);



    //Highlighting the difference.
    for(int i = 0;i < differenceList.size();i++)
    {
        cursorText1.setPosition(differenceList[i],QTextCursor::MoveAnchor);
        cursorText1.setPosition(differenceList[i] + 1,QTextCursor::KeepAnchor);
        cursorText1.setCharFormat(background1);

        cursorText2.setPosition(differenceList[i],QTextCursor::MoveAnchor);
        cursorText2.setPosition(differenceList[i] + 1,QTextCursor::KeepAnchor);
        cursorText2.setCharFormat(background2);
    }
}



