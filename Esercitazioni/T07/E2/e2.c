#include <stdio.h>
unsigned char mediacircostante(unsigned char* in, int i, int j, int w, int h){
    int count = 0;
    if (i+2<=h-1 && i-2>=0){
        if (j+2<=w-1 && j-2>=0){
            for (int riga = i-2;riga<=i+2;riga++){
                for (int col = j-2; col<=j+2;col++){
                    count += in[riga*w+col];
                }
            }
            count /= 25;
            return (unsigned char)count;
        }
    }
        return in[i*w+j];
}

void blur5(unsigned char* in, unsigned char* out, int w, int h){
    for (int i = 0;i<h;i++){
        for (int j=0; j<w;j++){
            out[i*w+j] = mediacircostante(in,i,j,w,h);
        }
    }
}