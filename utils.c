#include "utils.h"
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


void delims(char* output, int varsize, char** input, char* delim){
    if (**input == '\0'){
        return;
    }
    if (strchr(delim, **input)){
        *(input) += 1;
        return;
    }
    if (!isspace(**input)){
    *(output + varsize) = **input;
    *(output + varsize + 1) = '\0';
    varsize += 1;
    }
    *(input) += 1;
    delims(output, varsize, input, delim);
}

void stack_init(Stack *s, int element_size){
    s->elementSize = element_size;
    s->capacity = 32;
    s->data = malloc(s->capacity * s->elementSize);
    s->top = -1;
}

void stack_push(Stack* s, const void* data){
    if (s->top+1 >=s->capacity){
        s->capacity *= 2;
        s->data = realloc(s->data, s->capacity * s->elementSize);
    }
    s->top++;
    void* target = (char*)s->data + s->top * s->elementSize; // char* moves 1 byte, void* cant do arithmetic
    memcpy(target, data, s->elementSize);
}

void stack_pop(Stack *s, void* out_value){
    if (s->top < 0) return;
    void* source = (char*)s->data + s->top * s->elementSize;
    if (out_value){
        memcpy(out_value, source, s->elementSize);
    }
    s->top--;
}

void stack_free(Stack *s){
    free(s->data);
    s->top = -1;
    s->capacity = 0;
}
