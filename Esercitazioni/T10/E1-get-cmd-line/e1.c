//SCRIVERE LA SOLUZIONE QUI...

#include "e1.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_cmd_line(char* argv[64]){
    char riga[1024];
    fgets(riga,1024,stdin);

    int i = 0;
    char* token = strtok(riga, " \t\n");
    
    while (i<64 && token != NULL){
        argv[i] = strdup(token);
        i++;
        token = strtok(NULL, " \t\n");
    }
    argv[i] = NULL;
}