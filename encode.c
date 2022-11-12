#include "codec.h"
#include "string.h"

int main(int argc ,char* argv[]){
    char* dst = malloc(strlen(argv[1]));
    if(!dst){
        perror("The alocate doesn't success \n");
        exit(1);
    }
    encode(argv[1], dst, strlen(argv[1]));
    printf("%s \n", dst);
    free(dst);
    return 0;
}