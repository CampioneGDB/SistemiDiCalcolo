#include <stddef.h>
#include <stdio.h>


int main (){
    char * array1[] = {"I am tired of weakness", "tired of my feet of clay", "tired of days to come", "tired of digital distractions", NULL};
    int count = 0;
    while (array1[count] != NULL){
        count++;
    }
    printf("%d\n", count);
    return count;
}