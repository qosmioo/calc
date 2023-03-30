#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include <QMessageBox>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect (ui->pbt_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect (ui->pbt_pstvt_change, SIGNAL(clicked()), this, SLOT(operations()));
    connect (ui->pbt_dot, SIGNAL(clicked()), this, SLOT(pbt_dot_clicker()));
    connect (ui->pbt_persent, SIGNAL(clicked()), this, SLOT(operations()));
    connect (ui->pbt_del, SIGNAL(clicked()), this, SLOT(pbt_del_clicked()));
    connect (ui->pbt_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect (ui->pbt_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect (ui->pbt_mlt, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect (ui->pbt_dvd, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect (ui->pbt_equality, SIGNAL(clicked()), this, SLOT(btn_equality()));
    connect (ui->pbt_c, SIGNAL(clicked()), this, SLOT(btn_c()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::block_nums (bool block) {
    ui->pbt_0->setEnabled(!block);
    ui->pbt_1->setEnabled(!block);
    ui->pbt_2->setEnabled(!block);
    ui->pbt_3->setEnabled(!block);
    ui->pbt_4->setEnabled(!block);
    ui->pbt_5->setEnabled(!block);
    ui->pbt_6->setEnabled(!block);
    ui->pbt_7->setEnabled(!block);
    ui->pbt_8->setEnabled(!block);
    ui->pbt_9->setEnabled(!block);
}
void Calculator::block_operations (bool block) {
    ui->pbt_del->setEnabled(!block);
    ui->pbt_dot->setEnabled(!block);
    ui->pbt_persent->setEnabled(!block);
    ui->pbt_equality->setEnabled(!block);
    ui->pbt_plus->setEnabled(!block);
    ui->pbt_minus->setEnabled(!block);
    ui->pbt_dvd->setEnabled(!block);
    ui->pbt_mlt->setEnabled(!block);
    ui->pbt_pstvt_change->setEnabled(!block);
}

void Calculator::enable_dot () {
    if (!ui->lbl_number->text().contains('.') && !ui->lbl_number->text().contains('e')) {
        ui->pbt_dot->setEnabled(true);
    } else {
        ui->pbt_dot->setEnabled(false);
    }
}

void Calculator::digits_numbers() {

    if (ui->lbl_number->text().length() < 15) {
        //ui->pbt_equality->setEnabled(false);

        QPushButton *button = (QPushButton *)sender();

        QString str;

        if (ui->lbl_number->text().length() == 0) {
            ui->pbt_equality->setEnabled(true);
        }

        if (ui->lbl_number->text() == "0") {
            str = button->text();

        } else if (ui->lbl_number->text() == "-0") {
            str = "-" + button->text();
        }
        else {
            str = ui->lbl_number->text() + button->text();
        }

        ui->lbl_number->setText(str);

        if (ui->lbl_number->text().contains('e')) {
            block_nums(true);
        }

        enable_dot();
    }

}

void Calculator::pbt_dot_clicker () {
    if (ui->lbl_number->text().length() < 15) {
        if(!(ui->lbl_number->text().contains('.')) && !(ui->lbl_number->text().contains('e'))) {
            ui->lbl_number->setText(ui->lbl_number->text() + ".");
        }
    }
    ui->pbt_dot->setEnabled(false);
}

void Calculator::operations() {

    if (ui->lbl_number->text().contains('e')) {
        block_nums(true);
    }
    QPushButton *button = (QPushButton *)sender();
    double nums;
    QString str;

    if (button->text() == "+/-") {
        nums = (ui->lbl_number->text()).toDouble();
        nums = -1*nums;
        str = QString::number(nums, 'g', 15);
        ui->lbl_number->setText(str);
    } else if (button->text() == "%") {
        nums = (ui->lbl_number->text()).toDouble();
        nums = 0.01*nums;
        str = QString::number(nums, 'g', 15);
        ui->lbl_number->setText(str);

        if (ui->lbl_number->text().contains("e")) {
            block_nums(true);
            ui->pbt_del->setEnabled(false);
        }

        enable_dot();

    }
}

void Calculator::pbt_del_clicked() {
    if (!ui->lbl_number->text().contains ('e')) {
        QString str = ui->lbl_number->text();
        str.chop(1);
        if (str.isEmpty() || str == "-") {
            str = "0";
        }
        ui->lbl_number->setText(str);

    }
    enable_dot ();
}

void Calculator::btn_c() {
    ui->lbl_number->setText("0");

    block_nums(false);
    block_operations(false);
    ui->pbt_equality->setEnabled(false);

    operations_index = 0;
    first_num = 0;
}

void Calculator::math_operations() {
    ui->pbt_minus->setEnabled(false);
    ui->pbt_plus->setEnabled(false);
    ui->pbt_mlt->setEnabled(false);
    ui->pbt_dvd->setEnabled(false);
    ui->pbt_equality->setEnabled(false);

    operations_index = 0;

    QPushButton *button = (QPushButton *)sender();
    first_num = ui->lbl_number->text().toDouble();
    ui->lbl_number->setText(ui->lbl_number->text() + button->text());

    if (button->text() == "+") {
        operations_index = PLUS_IND;
    } else if (button->text() == "-") {
        operations_index = MINUS_IND;
     } else if (button->text() == "x") {
        operations_index = MULT_IND;
     } else if (button->text() == "/") {
        operations_index = DIV_IND;
     }

    ui->lbl_number->setText("");

    block_nums(false);

}

void Calculator::btn_equality() {
    ui->pbt_minus->setEnabled(true);
    ui->pbt_plus->setEnabled(true);
    ui->pbt_mlt->setEnabled(true);
    ui->pbt_dvd->setEnabled(true);
    ui->pbt_equality->setEnabled(true);

    double second_num = ui->lbl_number->text().toDouble();

    if (operations_index != 0){
        struct lbl_res calc = {operations_index, first_num, second_num, ""};
        ui->lbl_number->setText(QString::number(label_result(calc), 'g', 12));
        if (calc.message == "error") {
            ui->lbl_number->setText("press C.");
            QMessageBox::warning(this, "error.", "cannot divide by zero.");
            block_operations(true);
        }
    }

    if (ui->lbl_number->text().contains('e')) {
        block_nums(true);
    }
    ui->pbt_equality->setEnabled(false);
    enable_dot ();
}
