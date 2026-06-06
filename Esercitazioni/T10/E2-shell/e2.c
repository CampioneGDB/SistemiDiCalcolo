#include "e2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

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

void free_args(char* argv[]) {
    while (*argv) free(*argv++);
}

void esegui(char **argv) {
    pid_t pid_figlio;

    if ((pid_figlio = fork()) < 0) {
        perror("Errore ForK");
        exit(EXIT_FAILURE);
    }

    if (pid_figlio == 0) {
        execvp(*argv, argv);
        printf("Comando non riconosciuto %s\n", *argv);
        _exit(EXIT_FAILURE);
    }

    if (wait(NULL) < 0) {
        perror("Errore nel wait");
        exit(EXIT_FAILURE);
    }
}

int do_shell(const char* prompt){
    char* args[64];
    while(1){
        fputs(prompt,stdout);

        get_cmd_line(args);
    
        if(args[0] == NULL){
            continue;
        }
        if (strcmp(*args,"quit") == 0){
            free_args(args);
            break;
        }
        esegui(args);
        free_args(args);
    }
    return EXIT_SUCCESS;
}