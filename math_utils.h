#ifndef MATH_UTILS_H

#define MATH_UTILS_H


typedef struct {
     char condition[50];
     char output[50];
} Cond;
typedef struct {
     char variable[10];
     Cond conds[100];
} Function;

typedef enum{
    LITERAL,
    VARIABLE,
    LESS_THAN,
    GREATER_THAN,
    EQUALS_TO,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    UNIDENTIFIED,
} ElementType;

typedef struct {
    ElementType type;
    int value;
} Element;

typedef struct {
    int capacity;
    int count;
    Element* elements;
} EquationTokens;

typedef struct Node{
    ElementType type;
    struct Node* left;
    struct Node* right;
    int value;
} Node;

typedef Node* Equation;

EquationTokens tokenize_eq(char* input);
Node* make_node(ElementType type, int value, Node* left, Node* right);
int is_operator(ElementType t);
int precedence(ElementType t);

#endif
