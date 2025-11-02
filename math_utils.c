#include "utils.h"
#include <string.h>
#include "math_utils.h"

// input format: var{condition : output ; condition: output}
struct function parse_func(char* input){
    struct function func;
    delims(func.variable, 0, &input, "{");

    for (int i = 0; strlen(input) > 0; i++){
        delims(func.conds[i].condition, 0, &input, ":");
        delims(func.conds[i].output, 0, &input, ";}");
    }

    return func;
}
