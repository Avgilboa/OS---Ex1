#include "codec.h"

int encode(char* src ,char* dst, int len){
    int indx =0;
    while (indx < len)
    {
        if(isalpha(src[indx])){ dst[indx] = tolower(src[indx]);}
        else {dst[indx] = src[indx];}
        indx ++;
    }
    printf("%s\n", dst);
    return 1;
}

int decode(char* src ,char* dst, int len){
 
    int indx =0;
    while (indx < len)
    {
        if(isalpha(src[indx])) dst[indx] = toupper(src[indx]);
        else dst[indx] = src[indx];
        indx ++;
    }
    return 1;
}