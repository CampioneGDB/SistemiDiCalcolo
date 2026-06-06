#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int lenFile(const char* filename){
    FILE* f2 = fopen(filename, "r");
    fseek(f2,0,SEEK_END);
    int fin = ftell(f2) + 1;
    fclose(f2);
    return fin;
}

/*
char* load(const char* filename, unsigned* size){
    int len = lenFile(filename);
    FILE* f1 = fopen(filename, "r");
    char* ret = calloc(sizeof(char),len);
    int len2 = fread(ret,sizeof(char),len,f1);
    *size = len2;
    fclose(f1);
    return ret;
}
*/

char* load(const char* filename, unsigned* size){
    int fd = open(filename, O_RDONLY);
    int len = lseek(fd, 0, SEEK_END);
    lseek(fd,0,SEEK_SET);
    char* ret = calloc(sizeof(char),len);
    int lenfin = read(fd,ret,len);
    *size = lenfin;
    close(fd);
    return ret;
}
