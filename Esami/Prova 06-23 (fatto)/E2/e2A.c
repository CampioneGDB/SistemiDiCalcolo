#include "e2A.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int examStats(const char* fname, int * min, int * max, float * avg){
    FILE* f = fopen(fname, "r");
    float promossi = 0;
    int minimum = 40;
    int maximum = 0;
    float curr = 0;
    if (f == NULL){
        return -1;
    }
    char buffer[257];
    char* token;
    char* voto;
    while (fgets(buffer,256,f) != NULL){
        token = strtok(buffer,"-");
        while(token != NULL){
            voto = token;
            token = strtok(NULL,"-");
        }
        int esito = atoi(voto);
        if (esito >= 18){
            promossi++;
            curr+=esito;
            if (esito < minimum) minimum = esito;
            if (esito > maximum) maximum = esito;
        }
    }
    if(minimum != 40){
    *min = minimum;
    }
    *max = maximum;
    if (curr != 0){
    *avg = curr/promossi;
    }man
    return promossi;
}