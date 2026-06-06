#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

char* load(const char* filename, unsigned* size){
    FILE* f = fopen(filename, "r");
    if (f==NULL) return NULL;
    fseek(f, 0, SEEK_END);
    *size = ftell(f);
    fseek(f,0,SEEK_SET);
    char*read = calloc(sizeof(char),(*size)+1);
    *size = fread(read,1,*size,f);
    fclose(f);
    return read;
}
