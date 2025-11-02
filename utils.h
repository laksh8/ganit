#ifndef utils
#define utils

//vars

struct conds{
     char condition[50];
     char output[50];
};

struct function{
     char variable[10];
     struct conds conds[100];
};

//functions
void delims(char* output, int varsize, char** input, char* delim);

#endif
