#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e2.h"


int hourtotimestamp (const char *time){
        char hours[3];
        char minutes[3];
        hours[0] = time[0];
        hours[1] = time[1];
        hours[2] = '\0';
        minutes[0] = time[3];
        minutes[1] = time[4];
        minutes[2] = '\0';
        return 60*atoi(hours) + atoi(minutes);
    }

void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time){
    *list = NULL;
    struct booking * finale = NULL;
    int check = hourtotimestamp(time);
    for (int i = 0; i<size;i+=37){
        const char* buffer = &data[i];
        char tempoprenotazione[6];
        for (int j = 0; j<6;j++){
            tempoprenotazione[j] = buffer[j+32];
        }
        tempoprenotazione[5] = '\0';
    if (hourtotimestamp(tempoprenotazione) >= check){
        struct booking *prenot = malloc(sizeof(struct booking));
        prenot->time = calloc(7,sizeof(char));
        strcpy(prenot->time, tempoprenotazione);

        char posti[3];
        posti[0] = buffer[30];
        posti[1] = buffer[31];
        posti[2] = '\0';
        prenot->places = atoi(posti);

        char cognome[31];
        for (int i = 0; i<30; i++){
            if (buffer[i] == '_'){
                cognome[i] = '\0';
                break;
            }
            cognome[i] = buffer[i];
        }
        cognome[30] = '\0';
        prenot->surname = calloc(31,sizeof(char));
        strcpy(prenot->surname,cognome);

        prenot->next = NULL;
        if (*list == NULL){
            *list = prenot;
        }
        else{
            finale -> next = prenot;
        }
        finale = prenot;
    }
}
    return;
}