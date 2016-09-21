#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include  <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    check.push('O');
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            grid[i][j]=0;
        }
    }
//Создаю map кнопок с помощью QSignalMapper

    signalMapper = new QSignalMapper(this);

    connect(ui->b1, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);
    connect(ui->b2, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);
    connect(ui->b3, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);
    connect(ui->b4, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);
    connect(ui->b5, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);
    connect(ui->b6, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);
    connect(ui->b7, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);
    connect(ui->b8, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);
    connect(ui->b9, SIGNAL(clicked()), signalMapper, SLOT (map()), Qt::UniqueConnection);

    signalMapper->setMapping(ui->b1, 1);
    signalMapper->setMapping(ui->b2, 2);
    signalMapper->setMapping(ui->b3, 3);
    signalMapper->setMapping(ui->b4, 4);
    signalMapper->setMapping(ui->b5, 5);
    signalMapper->setMapping(ui->b6, 6);
    signalMapper->setMapping(ui->b7, 7);
    signalMapper->setMapping(ui->b8, 8);
    signalMapper->setMapping(ui->b9, 9);

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(pbSlot(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NewGame_triggered()
{
    close();
}

int MainWindow::checkWin()
    {
        // -1 - игра не окончена; 0 - ничья; 1 - победили крестики; 2 - победили нолики

        // Проверка на чью-нибудь победу
        for(int i = 1; i < 3; i++)

            if( (grid[0][0] == i && grid[1][0] == i && grid[2][0] == i) ||
                (grid[0][1] == i && grid[1][1] == i && grid[2][1] == i) ||
                (grid[0][2] == i && grid[1][2] == i && grid[2][2] == i) ||


                (grid[0][0] == i && grid[0][1] == i && grid[0][2] == i) ||
                (grid[1][0] == i && grid[1][1] == i && grid[1][2] == i) ||
                (grid[2][0] == i && grid[2][1] == i && grid[2][2] == i) ||


                (grid[0][0] == i && grid[1][1] == i && grid[2][2] == i) ||
                (grid[2][0] == i && grid[1][1] == i && grid[0][2] == i) )
                return i;


        int count = 0;
        QString str;
        for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] != 0){
                count++;
        qDebug()<<count;
            }}}
        // Заполнено все поле
        if(count == 9)
            return 0;

        return -1;
    }
void MainWindow::Handle(int over)
    {
        // Обработка конца игры



        switch(over)
        {
        case 0:
            ui->label->setText("Ничья!");
            break;
        case 1:
            ui->label->setText("Победили крестики!");
            break;
        case 2:
            ui->label->setText("Победили нолики!");
            break;
        }

    }
void MainWindow::pbSlot(int i) {
    QPushButton* p = (QPushButton*) signalMapper->mapping(i);

    if(i==1){o=0;l=0;}
    if(i==2){o=0;l=1;}
    if(i==3){o=0;l=2;}
    if(i==4){o=1;l=0;}
    if(i==5){o=1;l=1;}
    if(i==6){o=1;l=2;}
    if(i==7){o=2;l=0;}
    if(i==8){o=2;l=1;}
    if(i==9){o=2;l=2;}
    if(p->text()==NULL){
        if(check.top()=='X')
        {
            p-> setText(" ");
            p-> setStyleSheet("background-image: url(:X.png)");
            check.push('O');
            grid[o][l]=1;
        }
        else if(check.top()=='O')
        {
            p-> setText(" ");
            p-> setStyleSheet("background-image: url(:O.png)");
            check.push('X');
            grid[o][l]=2;
        }
    }
    Handle(checkWin());
}

