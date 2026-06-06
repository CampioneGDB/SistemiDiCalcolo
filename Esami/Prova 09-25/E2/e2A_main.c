#include "e2A.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score = 0;
int trials = 0;

static void test(const char* s, char c, int n, int correctResult) {
    trials++;

    int ok = 0;
    int maxFrasi = 0;

    int res = countOccurrencesParallel(s, c, n);
    // printf("test: %d, n: %d, l: %d, result: %d, expected result: %d\n", trials , n, l, res, correctResult);fflush(stdout);
    
    ok = res == correctResult;

    // printf("Test %d: %s\n", trials, ok ? "OK" : "errore");fflush(stdout);
    printf("Test %d: %d [corretto=%d] -> %s\n", trials, res, correctResult, correctResult == res ? "OK" : "errore" );
    
    score += ok;
}

int main() {
    const char s0[] = "Shall I compare thee to a summer's day?";
    const char s1[] = "Let me not to the marriage of true minds Admit impediments. Love is not love Which alters when it alteration finds, Or bends with the remover to remove";
    const char s2[] = "Where art thou, Muse, that thou forget'st so long To speak of that which gives thee all thy might? Spend'st thou thy fury on some worthless song, Darkening thy power to lend base subjects light? Return, forgetful Muse, and straight redeem In gentle numbers time so idly spent; Sing to the ear that doth thy lays esteem And gives thy pen both skill and argument. Rise, resty Muse, my love's sweet face survey, If Time have any wrinkle graven there; If any, be a satire to decay, And make Time's spoils despised every where. Give my love fame faster than Time wastes life; So thou prevent'st his scythe and crooked knife.";
    const char s3[] = "Unthrifty loveliness";
    const char s4[] = "Shakespeare";

    test(s0, 'e', 4, 2);
    test(s0, 'r', 8, 3);

    test(s1, 'm', 10, 2);
    test(s1, 'r', 2, 1);

    test(s2, 'n', 4, 1);
    test(s2, 's', 12, 7);

    test(s3, 'y', 10, 4);
    test(s3, 's', 11, 10);

    test(s4, 'e', 11, 4);
    test(s4, 'r', 6, 5);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
