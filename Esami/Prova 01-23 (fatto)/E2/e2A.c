#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decodeTextFile (const char * encoded_file, const char * key, char **decoded_text){
    FILE* f1 = fopen(key, "r");
    char chiave[60];
    char finale[1000];
    char c;
    fgets(chiave,60,f1);
    fclose(f1);
    FILE* f2 = fopen(encoded_file, "r");
    int i = 0;
    while ((c=fgetc(f2)) != EOF){
        if (c >= 65 && c <= 122){
            finale[i] = chiave[c-65];
        }
        else{
            finale[i] = c;
        }
        i++;
    }
    finale[i] = '\0';
    *decoded_text = calloc(sizeof(char),i+1);
    strncpy(*decoded_text,finale,i);
    return;
}