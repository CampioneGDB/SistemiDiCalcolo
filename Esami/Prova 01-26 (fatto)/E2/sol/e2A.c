#include "../e2A.h"
#include <stdio.h>
#include <assert.h>


void getStudents(const char * filename, student * in_list, int min_mark, char initial_letter) {
    FILE * fd = 0;  
    fd = fopen(filename, "w");
    assert(fd != NULL);
    
    //scorriamo la lista in ingresso
    student * temp = in_list;
    while (temp != 0){
        //controlliamo il voto dello studente e la lettera iniziale del cognome
        //Se il voto è >= min_mark E il cognome inizia con initial_letter, scriviamo su file
        if (temp->mark >= min_mark && temp->surname[0] == initial_letter)
            fprintf(fd, "%s %s - %d\n", temp->surname, temp->name, temp->mark);
        temp = temp->next;
    }


    //Chiudiamo il file se è stato aperto
    if (fd!=NULL) fclose(fd);
    return;
}
