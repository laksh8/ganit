#ifndef UTILS_H
#define UTILS_H

typedef struct {
    void* data;
    int elementSize;
    int capacity;
    int top;
} Stack;

//functions
void stack_init(Stack* s, int element_size);
void stack_push(Stack* s, const void* value);
void stack_pop(Stack* s, void* out_value);
void stack_free(Stack* s);

#endif
