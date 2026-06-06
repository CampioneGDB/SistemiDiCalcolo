#include "e2A.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int conta(const char* word, const char c){
    int len = strlen(word);
    int count = 0;
    for (int i = 0; i<len;i++){
        if (word[i] == c){
            count++;
        }
    }
    return count;
}

int wordWithMaxCount(const char* text, const char c, char ** word){
    if (text == NULL || *text == '\0') {
        return 0;
    }
    *word = calloc(sizeof(char),64);
    char* token = calloc(sizeof(char), 64);
    char* token2 = calloc(sizeof(char), 64);
    char* appoggio = calloc(sizeof(char), 1024);
    strcpy(appoggio, text);
    token = strtok(appoggio, " ");
    int max = conta(token,c);
    while (token != NULL){
        if (conta(token,c) > max){
            max = conta(token,c);
        }
        token = strtok(NULL," ");
    }
    if (max == 0){
        return max;
    }
    char* appoggio2 = calloc(sizeof(char), 1024);
    strcpy(appoggio2, text);
    token2 = strtok(appoggio2, " ");

    while (token2 != NULL){
        if (conta(token2,c) == max){
            strcpy(*word,token2);
            break;
        }
        token2 = strtok(NULL," ");
    }
    
    return max;
    
}