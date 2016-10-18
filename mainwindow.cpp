#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *btn[9] = {ui->b1, ui->b2, ui->b3,
                           ui->b4, ui->b5, ui->b6,
                           ui->b7, ui->b8, ui->b9};

    for(int i=0; i<9; i++)
    {
        b[i]=btn[i];
        connect(b[i], SIGNAL(clicked()), this, SLOT(on_clicked()));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

//////////////////////////////////////////////////////////////////////////
////////////////////////                     /////////////////////////////
////////////////////////    КНОПКИ [Х][О]    /////////////////////////////
////////////////////////                     /////////////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow::on_clicked()
{

    if(type==1){
        if(((QPushButton*)sender())->text()==NULL){
            if(play){
                ((QPushButton*)sender())->setText("X"); play = false;
            }
            else
            {
                ((QPushButton*)sender())->setText("O"); play = true;
            }
            checkWin();
        }
    }
    if(type==2)
    {
        if(first==0){
            if(((QPushButton*)sender())->text()==NULL){
                if(play){
                    ((QPushButton*)sender())->setText("X"); play = false;
                }
                else
                {
                    ((QPushButton*)sender())->setText("O"); play = true;
                }
                first=1;
            }

            checkWin();

        }

        if(first==1)
        {
            comp();
            first=0;
            checkWin();
        }
        play=player;

    }

}


//////////////////////////////////////////////////////////////////////////
//////////////////////                         ///////////////////////////
//////////////////////    ПРОВЕРКА НА ПОБЕДУ   ///////////////////////////
//////////////////////                         ///////////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow::checkWin()
{

    if(     (b[0]->text() == "X" && b[1]->text() == "X" && b[2]->text() == "X") ||
            (b[3]->text() == "X" && b[4]->text() == "X" && b[5]->text() == "X") ||
            (b[6]->text() == "X" && b[7]->text() == "X" && b[8]->text() == "X") ||
            (b[0]->text() == "X" && b[3]->text() == "X" && b[6]->text() == "X") ||
            (b[1]->text() == "X" && b[4]->text() == "X" && b[7]->text() == "X") ||
            (b[2]->text() == "X" && b[5]->text() == "X" && b[8]->text() == "X") ||
            (b[0]->text() == "X" && b[4]->text() == "X" && b[8]->text() == "X") ||
            (b[2]->text() == "X" && b[4]->text() == "X" && b[6]->text() == "X") )
    {
        textVal=ui->xval->text().toInt()+1;
        ui->xval->setText(QString::number(textVal));
        reset();
    }

    if(     (b[0]->text() == "O" && b[1]->text() == "O" && b[2]->text() == "O") ||
            (b[3]->text() == "O" && b[4]->text() == "O" && b[5]->text() == "O") ||
            (b[6]->text() == "O" && b[7]->text() == "O" && b[8]->text() == "O") ||
            (b[0]->text() == "O" && b[3]->text() == "O" && b[6]->text() == "O") ||
            (b[1]->text() == "O" && b[4]->text() == "O" && b[7]->text() == "O") ||
            (b[2]->text() == "O" && b[5]->text() == "O" && b[8]->text() == "O") ||
            (b[0]->text() == "O" && b[4]->text() == "O" && b[8]->text() == "O") ||
            (b[2]->text() == "O" && b[4]->text() == "O" && b[6]->text() == "O") )
    {
        textVal=ui->oval->text().toInt()+1;
        ui->oval->setText(QString::number(textVal));
        reset();
    }

    op=0;
    for(int i=0;i<9;i++)
    {
        if(b[i]->text()!=NULL)
        {
            op++;
        }
    }
    if(op==9){
        reset();
    }

}


//////////////////////////////////////////////////////////////////////////
/////////////////////                           //////////////////////////
/////////////////////   ОЧИСТКА ИГРОВОГО ПОЛЯ   //////////////////////////
/////////////////////                           //////////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow:: reset()
{
    for(int i=0;i<9;i++)
    {
        b[i]->setText(NULL);
    }
    play=player;
    first=0;
}


//////////////////////////////////////////////////////////////////////////
////////////////////////                     /////////////////////////////
////////////////////////   ПОЛНАЯ ОЧИСТКА    /////////////////////////////
////////////////////////                     /////////////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow:: clear()
{
    reset();
    ui->xval->setText("0");
    ui->oval->setText("0");
}


//////////////////////////////////////////////////////////////////////////
///////////////////////                       ////////////////////////////
///////////////////////   ИГРА С КОМПЬЮТЕРОМ  ////////////////////////////
///////////////////////                       ////////////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow:: comp()
{
    counter=0;
    for(int i=0;i<9;i++)
    {
        if(b[i]->text()!=NULL)
        {
            counter++;
        }
    }

    if(counter!=9)
    {
        if(level=="easy")
        {
            while(k)
            {
                int random=rand()%8;
                if(b[random]->text()==NULL)
                {
                    if(play){
                        b[random]->setText("X"); play = false;// checkWin();
                    }
                    else
                    {
                        b[random]->setText("O"); play = true;// checkWin();
                    }
                    k=false;
                }
            }
        }
        else if (level=="middle")
        {
            if(play){//если игрок играет за Х

                middleForXorO(0,1,2,"O");
                middleForXorO(3,4,5,"O");
                middleForXorO(6,7,8,"O");
                middleForXorO(0,3,6,"O");
                middleForXorO(1,4,7,"O");
                middleForXorO(2,5,8,"O");
                middleForXorO(0,4,8,"O");
                middleForXorO(2,4,6,"O");

                if(play){
                    while(k){
                        int random=rand()%8;
                        if(b[random]->text()==NULL)
                        {
                            b[random]->setText("X"); play = false;
                            k=false;
                        }
                    }
                }
            }

            else if(!play){//если игрок играет за O

                middleForXorO(0,1,2,"X");
                middleForXorO(3,4,5,"X");
                middleForXorO(6,7,8,"X");
                middleForXorO(0,3,6,"X");
                middleForXorO(1,4,7,"X");
                middleForXorO(2,5,8,"X");
                middleForXorO(0,4,8,"X");
                middleForXorO(2,4,6,"X");
                if(!play){
                    while(k){
                        int random=rand()%8;
                        if(b[random]->text()==NULL)
                        {
                            b[random]->setText("O"); play = true;
                            k=false;
                        }
                    }
                }
            }
        }

        else if (level=="hard")
        {

        }
    }
    k=true;
}

//////////////////////////////////////////////////////////////////////////
////////////////////////                     /////////////////////////////
////////////////////////   СРЕДНИЙ УРОВЕНЬ   /////////////////////////////
////////////////////////                     /////////////////////////////
//////////////////////////////////////////////////////////////////////////

void MainWindow:: middleForXorO(int i, int j, int z, QString XorO)
{
    if(XorO=="O")
    {
        if  (play&&((b[i]->text() == XorO && b[j]->text() == XorO)||(b[j]->text() == XorO && b[z]->text() == XorO) || (b[i]->text() == XorO && b[z]->text() == XorO)))
        {
                 if (play && b[i]->text()==NULL){b[i]->setText("X"); play = false;}
            else if (play && b[j]->text()==NULL){b[j]->setText("X"); play = false;}
            else if (play && b[z]->text()==NULL){b[z]->setText("X"); play = false;}
        }

    }
    else if(XorO=="X")
    {
        if  (!play&&((b[i]->text() == XorO && b[j]->text() == XorO)||(b[j]->text() == XorO && b[z]->text() == XorO) || (b[i]->text() == XorO && b[z]->text() == XorO)))
        {
                 if (!play && b[i]->text()==NULL){b[i]->setText("O"); play = true;}
            else if (!play && b[j]->text()==NULL){b[j]->setText("O"); play = true;}
            else if (!play && b[z]->text()==NULL){b[z]->setText("O"); play = true;}
        }

    }
}


//////////////////////////////////////////////////////////////////////////
////////////////////////                     //////////////////////////////
////////////////////////   КНОПКА "В МЕНЮ"   //////////////////////////////
////////////////////////                     //////////////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow::on_bmenu_clicked()
{
    clear();
    ui->stackedWidget->setCurrentIndex(0);

}


//////////////////////////////////////////////////////////////////////////
///////////////////                                 //////////////////////
///////////////////   КНОПКА "ИГРА С КОМПЬЮТЕРОМ"   //////////////////////
///////////////////                                 //////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow::on_PvE_clicked()
{
    type=2;
    ui->stackedWidget->setCurrentIndex(4);

}


//////////////////////////////////////////////////////////////////////////
//////////////////////                         ///////////////////////////
//////////////////////   КНОПКА "ДВА ИГРОКА"   ///////////////////////////
//////////////////////                         ///////////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow::on_PvP_clicked()
{
    type=1;
    ui->stackedWidget->setCurrentIndex(1);

}

//////////////////////////////////////////////////////////////////////////
/////////////////////                           //////////////////////////
/////////////////////   КНОПКИ ВЫБОРА Х или О   //////////////////////////
/////////////////////                           //////////////////////////
//////////////////////////////////////////////////////////////////////////

void MainWindow::on_Xfirst_clicked()
{
    player=true;
    play=player;
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Ofirst_clicked()
{
    player=false;
    play=player;
    ui->stackedWidget->setCurrentIndex(3);
}

//////////////////////////////////////////////////////////////////////////
/////////////////////                           //////////////////////////
/////////////////////   КНОПКИ ВЫБОРА УРОВНЯ    //////////////////////////
/////////////////////        СЛОЖНОСТИ          //////////////////////////
//////////////////////////////////////////////////////////////////////////

void MainWindow::on_easy_clicked()
{
    level="easy";
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_middle_clicked()
{
    level="middle";
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_hard_clicked()
{
    level="hard";
    ui->stackedWidget->setCurrentIndex(1);
}
