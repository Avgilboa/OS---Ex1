#include <stdio.h>
#include <stdlib.h>
int cmprFiles(FILE* ptr1, FILE* ptr2);
/** This code compare two files and print if they identicxl or not**/
int cmprFiles(FILE* ptr1, FILE* ptr2){
    int char1 , char2;
    if (ptr1 && ptr2) {
        do
        {
            char1 = getc(ptr1);
            char2 = getc(ptr2);
            if(char1 != char2){
                return 0;
            }
        }while(char1!= EOF && char2!= EOF);
        if(char1!=EOF || char2!=EOF){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage : cmp <file1> <file2>");
        exit(1);
    }
    FILE * f1;
    FILE* f2;
    if((f1 = fopen(argv[1], "r")) ==NULL || (f2 = fopen (argv[2], "r")) ==NULL ){
        printf("The file is not exsist");
        exit(1);
    }
    if(cmprFiles(f1, f2)){
        printf("Identical\n");
    }
    else{
        printf("Not identical\n");
    }
    fclose(f1);
    fclose(f2);
    return 0;
}