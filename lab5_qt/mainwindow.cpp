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
    string s = "Press the <Equal> or <Inequal> button to start ";
    s.append("\n");
    s+="You can freely change the text while comparing them";
     s.append("\n");
    s+="Use the <Restart> button to get back the original version";
       s.append("\n");
//    fp=fPair(s,s+"The differences will be highlighted","");
       fp=fPair();
       fp.c0=s;
       fp.c1=s+"The differences will be highlighted";

    on_btnCompare_released();
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::find(string name)
{
    for (int i=0;i<ufset.size();i++)
    {
        if (ufset[i]->getName()==name)
            return i;
    }
    return -1;
}

void MainWindow::ClearAll()
{
    ui->textEdit1->clear();
    ui->textEdit2->clear();
}




void MainWindow::on_btnCompare_released()
{
    ui->filename0->setText(QString::fromStdString(fp.s0).toUtf8());
    ui->filename1->setText(QString::fromStdString(fp.s1).toUtf8());
    ui->textEdit1->setText(QString::fromStdString(fp.c0).toUtf8());
    ui->textEdit2->setText(QString::fromStdString(fp.c1).toUtf8());
    ui->label->setText(QString::fromStdString(fp.info).toUtf8());
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


ufs::ufs(const string &filename) : filename(filename) {
    p =this;
}

void ufs::setParent(ufs *parent) {
    this->p=parent;
}

ufs *ufs::getParent()
{
    ufs *parent =p;
    while (!parent->isRoot())
        parent=parent->getParent();
    return parent;
}



void MainWindow::on_btnequal_released()
{
    //先处理上一个
    if (fp.info!="")
    {
        int num0 = find(fp.s0);
        int num1 = find(fp.s1);
        ufset[num0]->setParent(ufset[num1]);
        o.add(1,fp.s0,fp.s1);
    }
    fp =i.next();
    if(fp.s0!="")
    {
        int num0 = find(fp.s0);
        if (num0==-1)
        {
            ufs *  tmp =new ufs(fp.s0);
            ufset.push_back(tmp);
            num0 = find(fp.s0);
        }
        int num1 = find(fp.s1);
        if (num1==-1)
        {
            ufs *  tmp =new ufs(fp.s1);
            ufset.push_back(tmp);
            num1 = find(fp.s0);
        }
        if ( ufset[num0]->getParent()!= ufset[num1]->getParent()&&(!ufset[num0]->isRoot())&&(!ufset[num1]->isRoot()))
        {
            fp.info=info2;
        }

    }

    on_btnCompare_released();
}


void MainWindow::on_btnEqual_released()
{
    if (fp.info!="")
    {
        o.add(0,fp.s0,fp.s1);
    }
    fp =i.next();
    on_btnCompare_released();
}

