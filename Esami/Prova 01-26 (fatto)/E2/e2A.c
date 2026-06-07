#include "e2A.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void getStudents(const char * filename, student * in_list, int min_mark, char initial_letter){
    FILE* f = fopen(filename, "w");
    while(in_list != NULL){
    char cog[20]; 
	char nom[20];
	int voto;
    strcpy(cog, in_list->surname);
    strcpy(nom, in_list->name);
    voto = (in_list)->mark;
    in_list = in_list->next;
    if (*cog == initial_letter && voto >= min_mark){
    fprintf(f,"%s %s - %d\n",cog,nom,voto);
    }
    }
    fclose(f);
}