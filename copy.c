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
#include<string.h>

#define RW_BLOCK 10
int CopyContent(int fsource, int fddst){
    ssize_t readBytes, wroteBytes;
    char *buf[RW_BLOCK];
    lseek(fddst,0,SEEK_SET); //start the writing from the begining of the file
    do
    {
        readBytes = read(fsource, buf, RW_BLOCK); //read every time 10 byte from file 1
        if (readBytes < 0)
        {
            printf("I/O errors\n");
            exit(-10);
        }

        wroteBytes = write(fddst, buf, readBytes); // write the bytes we read to file 2
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

    // without -l
    if(argc ==3){
        char *dest = argv[2];
        char *src= argv[1];
        int fddst;
        int fdsrc;
        if ((fdsrc = open(src ,O_RDONLY)) < 0) //open file 1 for read
        {
            perror(" cant open sorce file");
            exit(1);
        }
        if ((fddst = open(dest ,O_RDONLY | O_WRONLY | O_TRUNC | O_WRONLY|O_CREAT , 0666)) < 0) //open file 2 to write
        {
            perror(" cant open dest file");
            exit(1);
        }
        CopyContent(fdsrc,fddst);
    /// close the files in the CopyContent function
	}
//with -l option    
    if(argc ==4){
        // first if the flag is not -l exit
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
        int fsource;
        int fddst;  
        //char *sourc = argv[2];
        char *dest = argv[3];
        /** 
     *   open src file with the adress and for ReadOnly and check that we dont get errors
    *     open the name of the copy file and to write only, and if its nod exsist create it
    * 
    * **/
        if ((fddst = open(dest ,O_RDONLY | O_WRONLY | O_TRUNC | O_WRONLY | O_CREAT , 0666)) < 0)
        {
            perror(" cant open dest file");
            exit(1);
        }
        char path[PATH_MAX];
        struct stat sb;
        
        if(stat(argv[2],&sb)==-1)
        {
            perror("cant find the stat");
            exit(1);
        }
        ssize_t wroteBytes, nbytes, bufsiz;
        char *buf;
        bufsiz = PATH_MAX;
        if (sb.st_size == 0)
        {
            bufsiz = PATH_MAX;
        }
        buf = malloc(bufsiz);
        nbytes = readlink(argv[2],buf,bufsiz);
        wroteBytes = write(fddst, buf, nbytes);
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
    /**
     * define buffer on size of a block.
     * read chars to cuff and write it on the new file.
     * when there is no chars to read it stop and close the files for use.
     * 
     * **/
        /*if(CopyContent(fsource, fddst)!=1){
            return 1;
        }*/
        free(buf);
        close(fddst);
    }
    return 0;
}
