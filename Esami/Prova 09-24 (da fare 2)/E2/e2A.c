#include "e2A.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int cercaEdEsporta(const char * filenameSource, const char * prefix, const char * filenameDest){
    FILE* f1 = fopen(filenameSource, "r");
    FILE* f2 = fopen(filenameDest, "w");
    if (f1 == NULL || f2 == NULL){
        printf("Errore");
        return 0;
    }

    char** fin;
    fin = calloc(sizeof(char*),20);

    char nome[31];
    char tel[15];
    char buffer[48];

    int z = 0;
    int esclusi = 0;

    while(fgets(buffer,sizeof(buffer),f1) != NULL){
        strncpy(nome,buffer,30);
        nome[30] = '\0';
        for (int a = 0; a<31;a++){
            if (nome[a] == '_'){
                nome[a] = '\0';
                break;
            }
        }
        printf("%s\n",nome);
        for(int j = 0;j<14;j++){
        tel[j] = buffer[30+j];
        }
        tel[14] = '\0';
        for (int a = 0; a<15;a++){
            if (tel[a] == '_'){
                tel[a] = '\0';
                break;
            }
        }

        if (strncmp(nome,prefix,strlen(prefix)) == 0){
            fin[z] = calloc(sizeof(char), 48);
            sprintf(fin[z],"%s,%s",nome,tel);
            printf("%s\n", fin[z]);
            z++;
        }
        else{
            esclusi++;
        }
    }

    for (int m = z-1;m>=0;m--){
        fprintf(f2,"%s\n", fin[m]);
    }

    fclose(f1);
    fclose(f2);
    return esclusi;



}