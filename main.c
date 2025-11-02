#include <stdio.h>
#include "math_utils.h"
#include "utils.h"


int main(void) {
    struct function func;
    func = parse_func("x {x >= 0 : x; x < 0 : -x }");
    printf("%s : %s\n", func.conds[1].condition, func.conds[1].output);
    return 0;
}
