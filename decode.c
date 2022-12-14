/// gcc decode.c -ldl -o decode
// Usage: ./decode <codec Type> <message>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

int
main(int argc, char **argv)
{
    void *handle;
    //
    int (*func)(char* , char* , int);
    // The function will return int and get this three parameters
    char *error;
    char* adress = malloc(sizeof(char) *(3 + strlen(argv[1]) +3 +1) );
    // the adress will fill with "lib" + the name of the libary + .so
    strcat(adress , "lib");
    strcat(adress , argv[1]);
    strcat(adress , ".so");
   handle = dlopen( adress , RTLD_LAZY);
   // check if we can open the file with the name we get from the user
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

   dlerror();    /* Clear any existing error */

   /* Writing: cosine = (double (*)(double)) dlsym(handle, "cos");
       would seem more natural, but the C99 standard leaves
       casting from "void *" to a function pointer undefined.
       The assignment used below is the POSIX.1-2003 (Technical
       Corrigendum 1) workaround; see the Rationale for the
       POSIX specification of dlsym(). */

   *(void **) (&func) = dlsym(handle, "decode");
   // check if the function is in the library 

   if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    int len =strlen(argv[2]);
    char* dest = malloc(sizeof(char) *(len+1));
   (*func)(argv[2], dest , len);
   // runnig the function
    printf("%s", dest);
    //print the result after the decoding
    dlclose(handle);
    // free all the alloctae memory used
    free(adress);
    free(dest);
    exit(EXIT_SUCCESS);
}