#include "e2A.h"
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int multicount(const char** s, char c, int n){
    if (c == 0 || n == 0){
        return -1;
    }
    for (int i = 0;i<n;i++){
        pid_t pid = fork();

        if (pid == 0){
            int count = 0;
            int len = strlen(s[i]);
            for (int j = 0;j<len;j++){
                if (s[i][j] == c){
                    count++;
                }
            }
            exit(count);
        }
    }
    int max = 0;
    for (int i = 0;i<n;i++){
        int status;
        wait(&status);
        if (WIFEXITED(status)){
            if (WEXITSTATUS(status) > max){
                max = WEXITSTATUS(status);
            }
        }
    }
    return max;
}
