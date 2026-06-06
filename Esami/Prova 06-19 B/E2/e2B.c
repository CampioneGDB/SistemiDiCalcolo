#include "e2B.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void make_files(int n, void (*f)(int i, char name[64], char buf[256])){
    for (int i = 0;i<n;i++){
        pid_t pid = fork();
        
        if (pid == 0){
            char nome[64];
            char buffer[256];
            f(i,nome,buffer);
            int fd = open(nome, O_WRONLY | O_CREAT | O_TRUNC, 0664);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            write(fd, buffer,sizeof(buffer));
            close(fd);
            exit(0);
        }
    }
    for (int z = 0;z<n;z++){
        int status;
        wait(&status);
    }
}