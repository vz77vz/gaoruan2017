#include<stdio.h>
#include<string.h>
#define MAXLINES 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int(*comp)(void*, void*));
int numcmp(char *, char *);
