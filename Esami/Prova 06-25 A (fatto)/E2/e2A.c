#include "e2A.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int contafrasi (char* stringa){
    int count = 0;
    for (int z = 0; z<strlen(stringa);z++){
        if (stringa[z] == '.'){
            count++;
        }
    }
    return count;
}

void numeroFrasiMaxParagrafi(const char* filename, int* maxNumeroFrasi){
    FILE * f = fopen(filename, "r");
    char** array = calloc(sizeof(char*),1024); //alloco spazio per 1024 paragrafi
    int i = 0;
    array[0] = calloc(sizeof(char),10000); //alloco spazio per il primo
    while(fgets(array[i],10000,f)!=NULL){


        i++;
        array[i] = calloc(sizeof(char),10000); //alloco spazio per 10000 caratteri
        
    }
    i--;
    for (int k = 0; k<i;k++){
        pid_t pid = fork();

        if (pid == 0){
            // --- ZONA FIGLIO ---
            int frasi = contafrasi(array[k]);
            
            // Se supera il limite degli 8 bit, lo "tagliamo" a 255
            if (frasi > 255) {
                frasi = 255;
            }
            
            exit(frasi);
        }
    }

    for (int k = 0; k<i;k++){
        int status;
        wait(&status);
        if (WIFEXITED(status)){
            if (*maxNumeroFrasi < WEXITSTATUS(status)){
                *maxNumeroFrasi = WEXITSTATUS(status);
            }
        }
    }
    free(array);
    fclose(f);
}