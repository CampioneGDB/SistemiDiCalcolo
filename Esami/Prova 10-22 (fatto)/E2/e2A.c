#include "e2A.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>


int loadStringsFromFile (const char * filename, char *** list){
    FILE *f = fopen(filename, "r");
    char buffer[1024];
    int i = 0;
    while(fgets(buffer,1024,f) != NULL){
        if (isalpha(buffer[0])){
            *list = calloc(sizeof(char*),1024);
            (*list)[i] = calloc(sizeof(char),1024);
            strcpy((*list)[i],buffer);
            i++;
        }
    }
    return i;
}
