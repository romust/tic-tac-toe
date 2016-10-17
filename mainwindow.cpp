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
        comp();
        checkWin();
        // player=play;
    }

}


//////////////////////////////////////////////////////////////////////////
//////////////////////                         ///////////////////////////
//////////////////////    ПРОВЕРКА НА ПОБЕДУ   ///////////////////////////
//////////////////////                         ///////////////////////////
//////////////////////////////////////////////////////////////////////////


void MainWindow::checkWin()
{
    dh++;
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
    if(dh==9){
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
        play=player;
    }
}


//////////////////////////////////////////////////////////////////////////
////////////////////////                     /////////////////////////////
////////////////////////   ПОЛНАЯ ОТЧИСТКА   /////////////////////////////
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
    if(((QPushButton*)sender())->text()==NULL){
        if(play){
            ((QPushButton*)sender())->setText("X"); play = false;
        }
        else
        {
            ((QPushButton*)sender())->setText("O"); play = true;
        }

    kk=0;
    for(int i=0;i<9;i++)
    {
        if(b[i]->text()!=NULL)
        {
            kk++;
        }
    }

    if(kk!=9)
    {
        if(level=="easy"){
        while(k){
            int random=rand()%8;
            if(b[random]->text()==NULL)
            {
                if(play){
                    b[random]->setText("X"); play = false;
                }
                else
                {
                    b[random]->setText("O"); play = true;
                }
                k=false;
            }
        }
        }
        else if (level=="middle"){}
        else if (level=="hard"){}


    }

    k=true;
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
