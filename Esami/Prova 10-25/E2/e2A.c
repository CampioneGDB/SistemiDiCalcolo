#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// inserisci la soluzione qui...
void getStudents(const char * filename, student * in_list, int min_mark){
    FILE *f = fopen(filename, "w");
    while (in_list != NULL){
        int mark = in_list->mark;
        if (mark >= 0 && mark >= min_mark && mark <= 31){
        fprintf(f,"%s %s - %d\n",strdup(in_list->surname),strdup(in_list->name),mark);
    }
        in_list = in_list->next;
    }
    fclose(f);
}
