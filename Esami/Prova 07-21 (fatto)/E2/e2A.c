#include "e2A.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int wordWithMaxCount(const char* text, const char c, char ** word){
    char* tmp = strdup(text);
    char* token = strtok(tmp," ");
    *word = calloc(sizeof(char),64);
    int max = 0;
    while (token != NULL){
        int count = 0;
        int len = strlen(token);
        for (int i = 0; i<len;i++){
            if (token[i] == c){
                count++;
            }
        }
        if (count > max){
            max = count;
            strcpy(*word, token);
        }
        token = strtok(NULL, " ");
    }
    free(tmp);
    return max;
}