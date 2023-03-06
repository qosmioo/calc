#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "math.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    void block_nums (bool block);
    void block_operations (bool block);
    void enable_dot();
    double first_num = 0;
    int operations_index = 0;

private slots:
    void digits_numbers ();
    void operations();
    void pbt_dot_clicker();
    void pbt_del_clicked();
    void math_operations();
    void btn_equality();
    void btn_c();
};
#endif // MAINWINDOW_H
