#include "e2C.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp(const void *p1, const void *p2)
{
    const char* v1 = *(const char* const *)p1;
    const char* v2 = *(const char* const *)p2;
    int val1 = atoi(v1);
    int val2 = atoi(v2);
    
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

void destinazioniSottoBudget(const char * filesorgente, const char * partenza, int budget, const char * filedestinazione){
    FILE* f = fopen(filesorgente, "r");
    FILE* f2 = fopen(filedestinazione, "w");

    char buffer[20];
    char dep[5];
    char arr[5];
    char costo[5];

    char **finaldep;
    finaldep = calloc(10,sizeof(char*));
    char **finalarr;
    finalarr = calloc(10,sizeof(char*));
    char **costofin;
    costofin = calloc(10,sizeof(char*));

    int i = 0;

    while (fgets(buffer, 20, f) != NULL){
        char* token = strtok(buffer, "-");
        strcpy(dep,token);
        token = strtok(NULL,"-");
        strcpy(arr,token);
        token = strtok(NULL,"-");
        strcpy(costo,token);
        if (atoi(costo) <= budget && strcmp(partenza,dep) == 0){
            finaldep[i] = calloc(sizeof(char),10);
            strcpy(finaldep[i],dep);
            finalarr[i] = calloc(sizeof(char),10);
            strcpy(finalarr[i],arr);
            costofin[i] = calloc(sizeof(char),10);
            strcpy(costofin[i],costo);
            i++;
        }
    }

    char** dup;
    dup = calloc(10,sizeof(char*));
    for (int j = 0;j<i;j++){
        dup[j] = calloc(sizeof(char),10);
        strcpy(dup[j],costofin[j]);
    }
    qsort(dup,i,sizeof(char*),cmp);

    for (int k = 0; k<i;k++){
        for (int z = 0; z<i;z++){
            if (strcmp(dup[k],costofin[z]) == 0){
                fprintf(f2,"%s-%s-%s",finaldep[z],finalarr[z],costofin[z]);
            }
        }
    }    



    fclose(f);
    fclose(f2);
}