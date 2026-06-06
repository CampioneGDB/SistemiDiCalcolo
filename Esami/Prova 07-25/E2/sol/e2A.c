#include "../e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    const char* s1;
    const char* s2;
    int l;
    int result;
} ThreadData;

void* analyzeCoupleThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int prefix_len = 0;
    const char* s1 = data->s1;
    const char* s2 = data->s2;

    while (*s1 && *s2 && *s1 == *s2) {
        prefix_len++;
        s1++;
        s2++;
    }

    data->result = (prefix_len >= data->l) ? 1 : 0;
    return NULL;
}

int countCouples(const char** s, int k, int l) {
    // Count actual strings in the array (NULL-terminated)
    int count = 0;
    while (s[count] != NULL) {
        count++;
    }

    if (k > count) return -1;
    if (k < 2) return -1;

    int effective_count = (k < count) ? k : count;  // Use minimum of k or actual count
    int total = 0;
    int num_pairs = effective_count * effective_count - effective_count; // All pairs without same elements

    pthread_t threads[num_pairs];
    ThreadData thread_data[num_pairs];
    int thread_index = 0;

    // Create threads for unique pairs within first k strings
    for (int i = 0; i < effective_count; i++) {
        for (int j = 0; j < effective_count; j++) {
            if (i == j) continue; // Skip identical elements

            thread_data[thread_index].s1 = s[i];
            thread_data[thread_index].s2 = s[j];
            thread_data[thread_index].l = l;
            
            if (pthread_create(&threads[thread_index], NULL, 
                             analyzeCoupleThread, &thread_data[thread_index]) != 0) {
                perror("pthread_create");
                exit(1);
            }
            thread_index++;
        }
    }

    // Wait for all threads to complete and sum results
    for (int i = 0; i < num_pairs; i++) {
        pthread_join(threads[i], NULL);
        total += thread_data[i].result;
    }

    return total;
}