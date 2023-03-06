#include "math.h"

double label_result (struct lbl_res calc, int &operations_index) {
    double label;
    if (calc.operations_index == PLUS_IND) {
        label = (calc.first_num + calc.second_num);
    } else if (calc.operations_index == MINUS_IND) {
        label = (calc.first_num - calc.second_num);
    } else if (calc.operations_index == DIV_IND) {
        label = (calc.first_num / calc.second_num);
   } else if (calc.operations_index == MULT_IND) {
        label = (calc.first_num * calc.second_num);
    }

    operations_index = 0;

    return label;
}
