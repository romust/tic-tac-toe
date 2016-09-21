#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QSignalMapper>
class QSignalMapper;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStack<char> check;
    int grid[3][3];

    int l, o;

int checkWin();
void Handle(int);
private slots:

    void on_NewGame_triggered();

    void pbSlot(int widget);
    /**void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_b9_clicked();**/

private:
    Ui::MainWindow *ui;
    QSignalMapper *signalMapper;
};

#endif // MAINWINDOW_H
