#ifndef MATH_H
#define MATH_H
#define PLUS_IND 1
#define MINUS_IND 2
#define DIV_IND 4
#define MULT_IND 3
#include "iostream"

struct lbl_res{
    int operations_index;
    double first_num;
    double second_num;
    std::string message; 
};

double label_result (struct lbl_res &calc);

#endif // MATH_H
