#include "e1.h"
#include <stdbool.h>
#include <stdio.h>

int is_suffix(const char* s1, const char* s2){
        printf("Test con: %s, %s\n",s1,s2);
        const char *ecx = s1;
        const char *esi = s2;
        bool al, ah,bh;
        A:
        if (*ecx){
            ecx++;
            printf("%c\n",*ecx);
            goto A;
        }
        B:
        if (*esi){
            esi++;
            printf("%c\n",*esi);
            goto B;
        }
        F:
        al = s1!=ecx;
        ah = s2!=esi;
        al = al && ah;
        if (al){
            ecx--;
            esi--;
            char dl = *esi;
            bh = *ecx == dl;
            if (bh){
                goto F;
            }
        }
            al = s1==ecx;
            char dl = *esi;
            ah = *ecx == dl;
            return ah && al;
        }