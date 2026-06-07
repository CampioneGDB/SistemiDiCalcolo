#include "e2B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

/*
off_t searchfile(char* filename, char c){
    FILE* f = fopen(filename, "r");
    char c2 = fgetc(f);
    while (c2 != EOF){
        if (c2 == c){
            printf("Evvai + %d\n", ftell(f));
            return ftell(f) -1;
        }
        c2 = fgetc(f);
    }
    return -1;
}
*/

off_t searchfile(char* filename, char c){
    int fd = open(filename, O_RDONLY);
    char d;
    while (read(fd,&d,1) != 0){
        if (d == c){
            printf("ciao");
            return lseek(fd,0,SEEK_CUR)-1;
        }
    }
    return -1;
}
