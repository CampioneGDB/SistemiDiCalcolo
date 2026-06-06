#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cerca(const char * filename, const char * prefix, struct contatto ** arrayMatches){
    *arrayMatches = malloc(32 * sizeof(struct contatto));
    FILE *f = fopen(filename, "r");
    int count = 0;
    char* buffer= calloc(48,sizeof(char));
    char nome [32];
    char telefono [16];

    while (fgets(buffer,48,f) != NULL){
        strncpy(nome,buffer,31);
        nome[31] = '\0';
        strncpy(telefono,buffer+31,15);
        telefono[15] = '\0';
        for (int i = 0; i<31;i++){
            if (nome[i] == '_'){
                nome[i] = '\0';
            }
            if (telefono[i] == '_'){
                telefono[i] = '\0';
            }
        }
        if (strncmp(prefix,nome,strlen(prefix)) == 0){
            strcpy((*arrayMatches)[count].nomecompleto,nome);
            strcpy((*arrayMatches)[count].numero, telefono);
            count++;
        }
        
    }

    fclose(f);
    free(buffer);
    return count;
}