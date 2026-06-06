int count_digits(const char*s){
    int eax = 0; //cnt
    const char* ecx = s; //s
    L:
    if (!*ecx) {
        goto R;
    }
    if (*ecx >= 48 && *ecx <= 57){
        eax++;
    }
    E:
    ecx++;
    goto L;

    R:
        return eax;
}