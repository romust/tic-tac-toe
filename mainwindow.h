#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QStackedWidget>


namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool play;
    bool player;
    QPushButton *b[9];
    int textVal;//переменная для перевода числа побед в строку
    int type;//тип игры (два игрока/игра с компьютером)
    bool k=true;//флаг, для поиска пустой рандомной ячейки
    int counter=0;//счетчик, для проверки заполненности поля
    QString level;//уровень сложности игры с компьютером
    int first=0;
    int op;

private slots:

    void reset();
    void clear();
    void on_clicked();
    void on_bmenu_clicked();
    void comp();
    void on_PvE_clicked();
    void on_PvP_clicked();
    void checkWin();
    void middleForXorO(int, int, int, QString);
    void on_Xfirst_clicked();
    void on_Ofirst_clicked();
    void on_easy_clicked();
    void on_middle_clicked();
    void on_hard_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
