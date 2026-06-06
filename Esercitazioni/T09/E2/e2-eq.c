#include "e2.h"

int crc32b(char *bytes, int n) {
    int magic = 0;
    magic = ~magic;
    int crc = magic;
    E:
    if (n){
        n--;
        int value;
        int byte = *bytes;
        bytes++;
        int index = crc;
        index = index^byte;
        get_constant(&value, index & 0xFF);
        crc = value ^ (crc>>8);
        goto E;
    }
    R:
    int eax = crc^magic;
    return eax;
}