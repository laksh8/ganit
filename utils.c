#include "utils.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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
