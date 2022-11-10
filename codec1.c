#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    int char1 , char2;
    FILE * f1;
    FILE* f2;
    f1= fopen("file1.txt", "r");
    f2 = fopen ("file2.txt", "r");
    if (f1 && f2) {
        while ((char1 = getc(f1))!= EOF  && (char2 = getc(f2)) !=EOF)
        {
            if(char1 !=char2){
                printf("The text is not equal");
                fclose(f1);
                fclose(f2);
                exit(1);
            }
        }
        if(char1 != EOF || char2!= EOF){
            printf("The text is not equal");
            fclose(f1);
            fclose(f2);
                exit(1);
        }
        fclose(f1);
        fclose(f2);
        printf("The files are equals");
    }
    return 0;
}