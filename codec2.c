#include <stdio.h>
#include "codec.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define RW_BLOCK 10

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("You nedd exactly two files");
        exit(1);
    }
    int fsorce, fddst;
    char *sourc = argv[1];
    char *dest = argv[2];
    printf("dest is %s:\n",dest);
    if ((fsorce = open(sourc, O_RDONLY)) < 0)
    {
        perror(" cant open sorce file");
        exit(-1);
    }

    if (fddst = open(dest, O_RDWR | O_CREAT) < 0)
    {
        perror(" cant open dest file");
        exit(1);
    }

    ssize_t readBytes, wroteBytes;
    char *buf[10];
    lseek(fddst,0,SEEK_SET);
    do
    {
        readBytes = read(fsorce, buf, RW_BLOCK);
        if (readBytes < 0)
        {
            printf("I/O errors\n");
            exit(-10);
        }

        wroteBytes = write(fddst, buf, readBytes);
        if (wroteBytes < RW_BLOCK)
        {
            printf("this is the error\n");
            if (errno == EDQUOT)
            {
                printf("ERROR: out of quota.\n");
            }
            else if (errno == ENOSPC)
            {
                printf("ERROR: not enough disk space.\n");
            }
        }
    } while (readBytes > 0);

    close(fsorce);
    close(fddst);
    return 0;
}
