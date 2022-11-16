// gcc -o libcodec2.so -shared -fPIC codec2.c

#include "codec.h"

int encode(char* src ,char* dst, int len){
    int indx =0;
    while (indx < len)
    {
        char temp = ~(src[indx]);
        temp+=1;
        dst[indx] = temp;
        indx++;
    }
    //printf("%s\n", dst);
    return 1;
}

int decode(char* src ,char* dst, int len){

    int indx =0;
    while (indx < len)
    {
        char temp = ~((src[indx]-1));
        dst[indx] = temp;
        indx++;
    }
    //printf("%s\n", dst);
    return 1;
}