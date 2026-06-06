#include "e3.h"
#include <stdio.h>
char *my_strpbrk(const char *s1, const char *s2){
    while (*s1 != '\0'){
        const char* f2 = s2;
        while(*f2 != '\0'){
            if (*f2 == *s1){
                printf("Finito");
                return s1;
            }
            else{
                f2++;
            }
        }
        s1++;
    }
    return NULL;
}
