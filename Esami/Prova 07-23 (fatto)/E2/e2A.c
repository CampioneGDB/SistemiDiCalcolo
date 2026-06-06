#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

int contavocali(const char * s){
    int len = strlen(s);
    int count = 0;
    for (int i = 0; i<len; i++){
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            count++;
        }
    }
    return count;
}

int vowelcount(const char** s, int n){
    if (n == 0 || s == NULL){
        return -1;
    }
    int count = 0;
    for (int i = 0; i<n; i++){
    pid_t pid = fork();
    if (pid == 0){
        exit(contavocali(s[i]));{
        }
    }
    }
    for (int i = 0; i<n;i++){
        int status;
        wait(&status);
        if (WIFEXITED(status)){
            count += WEXITSTATUS(status);
        }
    }
    return count;
}
