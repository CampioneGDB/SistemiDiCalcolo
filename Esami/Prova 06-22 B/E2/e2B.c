#include "e2B.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int wordcount(const char** s, int n){
    char** s2 = (char**) s;
    if (n==0){
        return -1;
    }
    int max = 0;
    int status;
    
    for (int i = 0;i<n;i++){
        char* strcurr = strdup(s2[i]);
        pid_t pid = fork();

        if (pid == 0){
            int count = 0;
            char* token = strtok(strcurr, " ");
            while (token != NULL){
                count++;
                token = strtok(NULL, " ");
            }
            exit(count);
        }

        wait(&status);
        if (WIFEXITED(status)){
            int curr = WEXITSTATUS(status);
            if (curr>max){
                max = curr;
            }
        }
    }
    return max;
}