#include <stdlib.h>
#include "e2.h"

int list_equal(const node_t *l1, const node_t *l2) {
    const node_t *edx = l1;
    const node_t *eax = l2;
    F:
    int cl = (edx == NULL);
    int ch = (eax == NULL);
    if (cl || ch){
        return (cl && ch);
    }
    if (edx->elem != eax->elem){
        return 0;
    }
    edx = edx->next;
    eax = eax->next;
    goto F;

}


typedef struct node_t {
    short elem;
    struct node_t *next;
} node_t; 8 byte