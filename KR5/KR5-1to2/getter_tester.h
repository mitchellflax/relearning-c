#include <stdio.h>
#include <ctype.h>

#define BUFSIZE	100

int getch(void);
void ungetch(int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getint(int *pn);
float getfloat(float *pf);
