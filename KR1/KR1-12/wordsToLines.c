#include <stdio.h>

#define IN	1 /* inside a word */
#define OUT	0 /* outside a word */

/* Takes inputs and outputs words one line at a time */
int main()
{
	/* when you reach a ' ', '\t',  or '\n' */
	/* put a newline */

	int currentChar, state;

	currentChar = 0;
	
	while((currentChar = getchar()) != EOF)
	{
		if(currentChar == ' ' || currentChar == '\t' || currentChar == '\n')
			putchar('\n');
		else
			putchar(currentChar);
	}

	return 0;
}

