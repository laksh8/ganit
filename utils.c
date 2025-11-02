#include "utils.h"
#include <ctype.h>
#include <stddef.h>
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
