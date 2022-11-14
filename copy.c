#include <stdio.h>
#include "codec.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include<limits.h>

#define RW_BLOCK 10
int CopyContent(int fsource, int fddst){
    ssize_t readBytes, wroteBytes;
    char *buf[RW_BLOCK];
    lseek(fddst,0,SEEK_SET);
    do
    {
        readBytes = read(fsource, buf, RW_BLOCK);
        if (readBytes < 0)
        {
            printf("I/O errors\n");
            exit(-10);
        }

        wroteBytes = write(fddst, buf, readBytes);
        if (wroteBytes < 0)
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

    close(fsource);
    close(fddst);
    return 1;
}
int main(int argc, char *argv[])
{
    if (argc != 3 && argc !=4 )
    {
        printf("Usage : copy <file1> <file2>");
        exit(1);

    }


    if(argc ==3){
        char * buff;
        char path[PATH_MAX];
        if(!realpath(argv[1],path))
        {
            perror("cant find the real path");
            exit(1);
        }
        printf("\nthe link path is: %s\n the real path is: %s",argv[1],path);
        int size=120;
        struct stat sb;
        if (stat(path, &sb) == -1) {
            perror("stat");
            exit(1);
        }
        buff = malloc(sizeof(char)*(sb.st_size+1));
        printf("%d",S_ISLNK(sb.st_mode));
        while(readlink(argv[1], buff, size) > size){
            size = size*2;
        }
        buff[size] = '\0';
        char *dest = argv[2];
        int fddst;
        int fdsrc;
        if ((fdsrc = open(path ,O_RDONLY)) < 0)
        {
            perror(" cant open sorce file");
            exit(1);
        }
        if ((fddst = open(dest ,O_WRONLY|O_CREAT , 0666)) < 0)
        {
            perror(" cant open dest file");
            exit(1);
        }
        CopyContent(fdsrc,fddst);
        //write(fddst, buff, size);
        close(fddst);

        printf("%s\n \n", buff);

        free(buff);
        printf("I-node number:            %ld\n", (long) sb.st_ino);

        printf("Mode:                     %lo (octal)\n",
                    (unsigned long) sb.st_mode);

        printf("Link count:               %ld\n", (long) sb.st_nlink);
        printf("Ownership:                UID=%ld   GID=%ld\n",
                    (long) sb.st_uid, (long) sb.st_gid);
        printf("Preferred I/O block size: %ld bytes\n",
                    (long) sb.st_blksize);
        printf("File size:                %lld bytes\n",
                    (long long) sb.st_size);
        printf("Blocks allocated:         %lld\n",
                    (long long) sb.st_blocks);

        printf("Last status change:       %s", ctime(&sb.st_ctime));
        printf("Last file access:         %s", ctime(&sb.st_atime));
        printf("Last file modification:   %s", ctime(&sb.st_mtime));
    }
    
    if(argc ==4){
            int opt = getopt(argc, argv,":if:l" );
            if(opt!= 'l'){
                printf("Usage : copy <file1> <file2>");
                exit(1);
            }
        
        /* 
            fsource - The status and action about the source file.
            fddst - The status and action about the new coping file.
            sourc - save the adress of the src file.
            dest - save the adress of the new file .
        */
        int fsource, fddst;  
        char *sourc = argv[2];
        char *dest = argv[3];
        /** 
     *   open src file with the adress and for ReadOnly and check that we dont get errors
    *     open the name of the copy file and to write only, and if its nod exsist create it
    * 
    * **/
        if ((fsource = open(sourc, O_RDONLY)) < 0) 
        {
            perror(" cant open sorce file");
            exit(-1);
        }
        
        if ((fddst = open(dest ,O_WRONLY|O_CREAT , 0666)) < 0)
        {
            perror(" cant open dest file");
            exit(1);
        }
    /**
     * define buffer on size of a block.
     * read chars to cuff and write it on the new file.
     * when there is no chars to read it stop and close the files for use.
     * 
     * **/
        if(CopyContent(fsource, fddst)!=1){
            return 1;
        }
        printf("file is copied\n");
    }
    return 0;
}
