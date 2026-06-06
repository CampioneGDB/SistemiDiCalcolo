#include "e2.h"

long f_opt(const short *v, unsigned n){
    unsigned j;
    long x = 0;
    for (j=0; j<n; ++j) x += v[j];
    return x;
}