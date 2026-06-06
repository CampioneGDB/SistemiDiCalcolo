#include "e1.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int parseCSV(const char* file, person_t** out, int minAge) {
    FILE* f = fopen(file,"r");
    *out = NULL;
    person_t* last = NULL;
    char tmp [65];
    if (f == NULL){
        return -1;
    }
    while(fgets(tmp,65,f) != NULL) {
        char* token = strtok(tmp,",");
        char* tempname = token;

        token = strtok(NULL,",");
        char* tempsurname = token;

        token = strtok(NULL,",");
        int year = atoi((&token[6]));

        token = strtok(NULL,",");
        char* temp_phd = token;

        if (year>=minAge){
            struct person_t* new = malloc(sizeof(struct person_t));
            (new)->name = strdup(tempname);
            (new)->surname = strdup(tempsurname);
            (new)->year = year;
            if (strncmp(temp_phd,"yes",3)==0){
                new->has_phd = 1;
            }
            else{
                new->has_phd = 0;
            }
            new->next = NULL;

            if (last == NULL){
                *out = new;
            }
            else{
                last->next = new;
            }
            last = new;
        }
    }
    fclose(f);

    return 0;
}