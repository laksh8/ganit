#include "utils.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math_utils.h"

// input format: var{condition : output ; condition: output}
Function parse_func(char* input){
    Function func;
    delims(func.variable, 0, &input, "{");

    for (int i = 0; strlen(input) > 0; i++){
        delims(func.conds[i].condition, 0, &input, ":");
        delims(func.conds[i].output, 0, &input, ";}");
    }

    return func;
}

EquationTokens init_equation(){
    EquationTokens eq;
    eq.count = 0;
    eq.capacity = 100;
    eq.elements = malloc(eq.capacity * sizeof(Element));
   return eq;
}

ElementType elementTypeClassify(char in){
    if (isalpha(in)){
        return VARIABLE;
    }
    if (isdigit(in)){
        return LITERAL;
    }

    switch (in) {
        case '+': return ADD;
        case '-': return SUBTRACT;
        case '*': return MULTIPLY;
        case '/': return DIVIDE;
        case '<': return LESS_THAN;
        case '>': return GREATER_THAN;
        case '=': return EQUALS_TO;
    }

    return UNIDENTIFIED;
}

EquationTokens tokenize_eq(char *input){
    EquationTokens eq = init_equation();
     if (!eq.elements) {
        perror("memory allocation failed");
        exit(1);
    }
    while (*input != 0){
        if (eq.count >= eq.capacity){
            eq.capacity *= 2;
            eq.elements = realloc(eq.elements,eq.capacity * sizeof(Element));
        }
        eq.elements[eq.count].value = *input;
        eq.elements[eq.count].type = elementTypeClassify(*input);
        eq.count += 1;
        input += 1;
    }
    return eq;
}
