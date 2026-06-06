unsigned int adler32_simplified(unsigned char* data, int len)
{
    int ebx = 0; //index
    unsigned int ebp = 1; //a
    unsigned int edi = 0; //b
    unsigned char* esi = data;

    F:
    if (ebx>=len){
        goto R;
    }
    ebp += esi[ebx];
    ebp = ebp & 0xFFFF;
    edi += ebp;
    edi = edi & 0xFFFF;
    ebx++;
    goto F;

    R:
    edi = edi << 16;
    edi = edi | ebp;
    return edi;

}