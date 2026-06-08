#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void getLargeTables(struct booking ** list, const char * filename, int num){
    FILE* f = fopen(filename, "r");
    *list = NULL;
    struct booking* tail = *list;
    char buffer[38];
    char nome[31];
    char numero[3];
    char time[6];
    while (fgets(buffer,38,f) != NULL){
        strncpy(nome,buffer,30);
        strcpy(buffer,buffer+30);
        strncpy(numero,buffer,2);
        strcpy(time,buffer+2);
        if (atoi(numero) >= num){
            struct booking* nuovo_nodo = malloc(sizeof(struct booking));
            nuovo_nodo->surname = malloc(sizeof(nome));
            int lenprovv = strlen(nome);
            for (int i = 0;i<lenprovv;i++){
                if (nome[i] == '_'){
                    nome[i] = '\0';
                    break;
                }
            }
            strcpy(nuovo_nodo->surname,nome);
            (nuovo_nodo->places = atoi(numero));
            nuovo_nodo->time = malloc(sizeof(time));
            strcpy(nuovo_nodo->time,time);
            //printf("%s - %d - %s\n", (*list)->surname, (*list)->places, (*list)->time);
            // Il nuovo nodo chiude sempre la lista per sicurezza
            nuovo_nodo->next = NULL;

            if (*list == NULL) {
                *list = nuovo_nodo;
                tail = nuovo_nodo;
            } else {
                tail->next = nuovo_nodo;
                tail = nuovo_nodo;       
            }
            
        }
    }
}