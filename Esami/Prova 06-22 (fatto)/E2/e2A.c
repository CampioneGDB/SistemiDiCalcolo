#include "e2A.h"
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int contaoccorrenze(char* s, char c){
    int count = 0;
    for (int i = 0; i<strlen(s);i++){
        if (s[i] == c){
            count++;
        }
    }
    return count;
}

int multicount(const char** s, char c, int n){
    int max = 0;
    if (c==NULL || n == 0){
        return -1;
    }
    for (int i = 0; i<n; i++){
    pid_t pid = fork();

    if (pid == -1){
        perror("errore nel fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0){
        int curr = contaoccorrenze(s[i],c);
        exit(curr);
    }
}
       
int status;
while(wait(&status) > 0)
    if (WIFEXITED(status))
        if (WEXITSTATUS(status) > max) max = WEXITSTATUS(status);

return max;
}


