#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void run(int* v, int n, int (*f)(int i)){
    for (int i = 0; i<n; i++){
        pid_t pid = fork();
        if (pid == 0){
            exit(f(i));
        }
    }

    for(int j = 0; j<n;j++){
        int status;
        wait(&status);
        if (WIFEXITED(status)){
            v[j] = WEXITSTATUS(status);
        }
    }
}
