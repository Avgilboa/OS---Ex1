#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int cmprFiles(FILE* ptr1, FILE* ptr2);

int CopyContent(int fsource, int fddst);

int encode(char* src ,char* dst, int len);
int decode(char* src ,char* dst, int len);