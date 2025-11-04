#ifndef utils
#define utils

typedef struct {
    void* data;
    int elementSize;
    int capacity;
    int top;
} Stack;

//functions
void delims(char* output, int varsize, char** input, char* delim);
void stack_init(Stack* s, int element_size);
void stack_push(Stack* s, const void* value);
void stack_pop(Stack* s, void* out_value);
void stack_free(Stack* s);

#endif
