#include <stdio.h>
#include <string.h>
#include "e1.h"

int cmp(const void* a, const void* b){
    person_t a1 = *(person_t*) a;
    person_t b1 = *(person_t*) b;
    return strcmp(a1.name,b1.name);
}

int cmp2(const void* a, const void* b){
    person_t* b1 = (person_t*) b;
    char* name = b1->name;
    char* key = (char*) a;
    return strcmp(key,name);
}

void sort_people(person_t p[], size_t n){
    qsort(p,n,sizeof(person_t),cmp);
}

person_t *find_person(char *key, person_t sorted[], size_t n){
        return bsearch(key,sorted,n,sizeof(person_t),cmp2);
    }
