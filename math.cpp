#include "math.h"

double label_result (struct lbl_res &calc) {
    double label = 0;
    if (calc.operations_index == PLUS_IND) {
        label = (calc.first_num + calc.second_num);
    } else if (calc.operations_index == MINUS_IND) {
        label = (calc.first_num - calc.second_num);
    } else if (calc.operations_index == DIV_IND) {
        if (calc.second_num != 0) {
            label = (calc.first_num / calc.second_num);
        } else {
            calc.message = "error";
        }
        
   } else if (calc.operations_index == MULT_IND) {
        label = (calc.first_num * calc.second_num);
    }

    calc.operations_index = 0;

    return label;
}
