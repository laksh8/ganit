#ifndef math_utils

#define math_utils


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
} Equation;

Function parse_func(char* input);
Equation parse_eq(char* input);

#endif
