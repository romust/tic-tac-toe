#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    check.push(2);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_NewGame_triggered()
{
    close();
}

void MainWindow::on_b1_clicked()
{
    if(check.top()==1)
    {
        ui->b1->setText("X");
        check.push(2);
    }
    else
    {
        ui->b1->setText("O");
        check.push(1);
    }
}
void MainWindow::on_b2_clicked()
{
    if(check.top()==1)
    {
        ui->b2->setText("X");
        check.push(2);
    }
    else
    {
        ui->b2->setText("O");
        check.push(1);
    }
}
void MainWindow::on_b3_clicked()
{
    if(check.top()==1)
    {
        ui->b3->setText("X");
        check.push(2);
    }
    else
    {
        ui->b3->setText("O");
        check.push(1);
    }
}
void MainWindow::on_b4_clicked()
{
    if(check.top()==1)
    {
        ui->b4->setText("X");
        check.push(2);
    }
    else
    {
        ui->b4->setText("O");
        check.push(1);
    }
}
void MainWindow::on_b5_clicked()
{
    if(check.top()==1)
    {
        ui->b5->setText("X");
        check.push(2);
    }
    else
    {
        ui->b5->setText("O");
        check.push(1);
    }
}
void MainWindow::on_b6_clicked()
{
    if(check.top()==1)
    {
        ui->b6->setText("X");
        check.push(2);
    }
    else
    {
        ui->b6->setText("O");
        check.push(1);
    }
}
void MainWindow::on_b7_clicked()
{
    if(check.top()==1)
    {
        ui->b7->setText("X");
        check.push(2);
    }
    else
    {
        ui->b7->setText("O");
        check.push(1);
    }
}
void MainWindow::on_b8_clicked()
{
    if(check.top()==1)
    {
        ui->b8->setText("X");
        check.push(2);
    }
    else
    {
        ui->b8->setText("O");
        check.push(1);
    }
}
void MainWindow::on_b9_clicked()
{
    if(check.top()==1)
    {
        ui->b9->setText("X");
        check.push(2);
    }
    else
    {
        ui->b9->setText("O");
        check.push(1);
    }
}
