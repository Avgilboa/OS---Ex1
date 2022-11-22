// gcc -o libcodec2.so -shared -fPIC codec2.c

#include "codec.h"

int encode(char* src ,char* dst, int len){
    int indx =0;
    while (indx < len)
    {
        char temp = ~(src[indx]) +1 ;
        // replace all the bits and adding 1
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
        char temp = ~((src[indx] -1));
        // remove 1 and than replace all the bits
        dst[indx] = temp;
        indx++;
    }
    //printf("%s\n", dst);
    return 1;
}

// int main(){
//     char temp =5;
//     char  dst;
//     encode(&temp, &dst, 1);
//     printf("%d \n", temp);
//     printf("%d", dst);
//     decode(&dst, &temp,1);
//     printf("\n %d \n", temp);
//     printf("%d", dst);
//     return 0;
// }