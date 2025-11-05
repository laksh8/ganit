#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math_utils.h"

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

Node* make_node(ElementType type, int value, Node *left, Node *right){
    Node* nd = malloc(sizeof(Node));
    nd->type = type;
    nd->left = NULL;
    nd->right = NULL;
    nd->value = value;
    return nd;
}

int precedence(ElementType t) {
    switch (t) {
        case MULTIPLY:
        case DIVIDE:
            return 2;
        case ADD:
        case SUBTRACT:
            return 1;
        case LESS_THAN:
        case GREATER_THAN:
        case EQUALS_TO:
            return 0;
        default:
            return -1;
    }
}

int is_operator(ElementType t) {
    return t == ADD || t == SUBTRACT || t == MULTIPLY || t == DIVIDE ||
           t == LESS_THAN || t == GREATER_THAN || t == EQUALS_TO;
}
