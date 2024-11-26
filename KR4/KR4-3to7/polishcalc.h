#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP	100
#define NUMBER '0'
#define MAXVAL	100
#define BUFSIZE	100


int sp = 0;
double val[MAXVAL];

int getch(void);
void ungetch(int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getop(char s[]);
void push(double f);
double pop(void);
