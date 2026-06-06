/*
typedef struct node_t {
    short elem; //2 byte
    struct node_t *next; /4 byte
} node_t; totale 8 byte
*/


#include <stdlib.h>
#include "e1.h"

int list_add_first(node_t **l, short elem) {
    node_t ** ecx = l; //l
    node_t *edx = *ecx; //p
    node_t *n = malloc(8); //n
    int eax = 0;
    if (n!=NULL){
        goto F;
    }
    goto E;
    
    F:
        n->elem = elem;
        n->next = edx;
        *ecx = n;
        eax = 0;
        return eax;
    E:
        eax = -1;
        return eax;
    
}