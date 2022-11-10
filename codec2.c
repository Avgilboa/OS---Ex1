#include <stdio.h>
#include "codec.h"
#include <stdlib.h>

int copyFiles(FILE* ptr1, FILE* ptr2){
    int char1 , char2;
    if (ptr1 && ptr2) {
        while((char1=getc(ptr1))!= EOF)
        {
            fputc(char1, ptr2);
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("You nedd exactly two files");
        exit(1);
    }
    FILE * f1;
    FILE* f2;
    if((f1 = fopen(argv[1], "r")) ==NULL || (f2 = fopen (argv[2], "w")) ==NULL ){
        printf("The file is not exsist");
        exit(1);
    }
    if(copyFiles(f1, f2)){
        printf("Copy\n");
    }
    fclose(f1);
    fclose(f2);
    return 0;
}