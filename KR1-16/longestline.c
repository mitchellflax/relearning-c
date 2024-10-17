#include <stdio.h>

// revising this program to actually just store 50 chars
// but to measure an arbitrarily long line
// and dropping a nasty long line in comment at the end of this sourcefile as evidence
#define MAXLINE 50


/* this program is broken */
/* leaving it for a while to return to it */
/* if we feed it this exact program as input, it breaks with an abort */
/* note that the copy is commented out */

int getMyLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{

	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getMyLine(line, MAXLINE)) > 0)
	{
		if(len > max)
		{
			max = len;
			copy(longest, line);
			printf("Found the new longest line! Max is now %d.\n", max);
		}
	}

	printf("Got to the evaluation of whether there was a line, max is %d\n", max);
	printf("max > 0 evaluates to %d\n", max > 0);
	if(max > 0) /* there was a line */
	{

		// let's just print the chars, and if that works it tells me my string termination is trash
		int j;
		for (j = 0; j < MAXLINE; j++)
			printf("%c \n", longest[j]);

		printf("%s\n", longest);
		printf("The longest was printed above.\n");
	}
	return 0;
}

/* new version of getMyLine not length-dependent */
int getMyLine(char line[], int maxline)
{
	int c, moreChars, i;
	
	// in this version the limit just tells us how much data we can store
	moreChars = 1;
	i = 0;
		
	while (moreChars == 1)
	{
		c = getchar();

		/* debugging */
		printf("c is %c\n", c);
		printf("moreChars is %d\n", moreChars);
		printf("i is %d\n", i);


		// if it's an EOF or newline, store a \0 char
		if (c == EOF || c == '\n')
		{
			printf("found an EOF or newline\n");
			line[i] = '\0';
			moreChars = 0;
		}

		// store it if we can
		if (i < maxline - 1 && c != EOF && c != '\n')
			line[i] = c;

		// now moved to the end
		if (c != EOF)
			i++;
			
	}

	printf("here's the char array now:\n");
	int j;
	for (j = 0; j < maxline; j++)
		printf("%c ", line[j]);

	printf("\n That was j of %d chars.\n", j);
	printf("returning i of %d\n", i);
	return i;

}


/* getMyLine: read a line into s, return length */
/*
int getMyLine(char s[], int lim)
{
	int c, i;
	


	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
*/

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	printf("COPY fn called: here's the char array of the 'from' now:\n");
	int j;
	for (j = 0; j < MAXLINE; j++)
		printf("%c ", from[j]);

	i = 0;
	while ((to[i] = from[i]) != '\0')
	{
		printf("copying happening\n");
		++i;
	}
}
