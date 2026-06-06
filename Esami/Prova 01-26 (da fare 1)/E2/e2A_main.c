#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score, trials;

static char * getOutput(const char * filename) {
    char * buf = (char *) malloc (4096 * sizeof(char));
    FILE *fp;
    char cmd[19];

    sprintf(cmd, "tr '\n' ' ' < %s", filename);

    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return NULL;
    }
    if (fgets(buf, 4095, fp) == NULL) buf = "";

    if (pclose(fp)) {
        printf("Command not found or exited with error status\n");
        return NULL;
    }

    return buf;
}

student * newStudent(char * surname, char * name, int mark, student * next){
    student * out = (student *) malloc(sizeof(student));
    strncpy(out->surname, surname, 20);
    out->surname[19] = 0;
    strncpy(out->name, name, 20);
    out->surname[19] = 0;
    out->mark = mark;
    out->next = next;
    return out;
}

student * init(){
    student * Z = newStudent("Blu", "Luca", 31, NULL);
    student * Y = newStudent("Arancioni", "Elena", 30, Z);
    student * X = newStudent("Verdi", "Marco", 29, Y);
    student * W = newStudent("Marrone", "Sofia", 28, X);
    student * V = newStudent("Verdi", "Paolo", 27, W);
    student * U = newStudent("Neri", "Chiara", 26, V);
    student * T = newStudent("Bianchi", "Lorenzo", 25, U);
    student * S = newStudent("Verdi", "Martina", 24, T);
    student * R = newStudent("Marrone", "Davide", 23, S);
    student * Q = newStudent("Rossi", "Federica", 22, R);
    student * P = newStudent("Blu", "Andrea", 21, Q);
    student * O = newStudent("Gialli", "Simone", 20, P);
    student * N = newStudent("Rosa", "Valentina", 19, O);
    student * M = newStudent("Arancioni", "Matteo", 18, N);
    student * L = newStudent("Grigi", "Alessia", 17, M);
    student * K = newStudent("Neri", "Gabriele", 16, L);
    student * J = newStudent("Bianchi", "Serena", 16, K);
    student * I = newStudent("Verdi", "Tommaso", 16, J);
    student * H = newStudent("Marrone", "Alice", 16, I);
    student * G = newStudent("Rossi", "Emanuele", 16, H);
    student * F = newStudent("Azzurra", "Giorgia", 16, G);
    student * E = newStudent("Viola", "Anna", 16, F);
    student * D = newStudent("Bianchi", "Alberto", 16, E);
    student * C = newStudent("Verdi", "Francesca", 16, D);
    student * B = newStudent("Marrone", "Gianni", 16, C);
    student * A = newStudent("Rossi", "Mario", 16, B);
    return A;
}

static void test(int num, const char * correct, const char * filename, char initial_letter) {
    trials++;
    student * list = init();
    student * ret = 0;

    getStudents(filename, list, num, initial_letter);
    int ok = strcmp(correct, getOutput(filename)) == 0;

    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
}

int main() {
    test(16, "Bianchi Alberto - 16 Bianchi Serena - 16 Blu Andrea - 21 Bianchi Lorenzo - 25 Blu Luca - 31 ", "A.txt", 'B');
    test(24, "Verdi Martina - 24 Verdi Paolo - 27 Verdi Marco - 29 ", "B.txt", 'V');
    test(23, "Marrone Davide - 23 Marrone Sofia - 28 ", "C.txt", 'M');
    test(28, "Arancioni Elena - 30 ", "D.txt", 'A');
    test(31, "Blu Luca - 31 ", "E.txt", 'B');

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
