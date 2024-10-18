#include <stdio.h>

// K&R says lines of length of 80 or more, so you'd set threshold of 79
#define THRESHOLD 10

void printLongLine(char start[], char next);

/* print lines with more than THRESHOLD characters */
int main()
{

	char storedChars[THRESHOLD];
	int c, i;

	i = 0;

	/* store characters up to the threshold 
	 if there are fewer than the threshold, 
	 we don't care if there's junk stored later on */
	while ((c = getchar()) != EOF)
	{
		/* if we're below the threshold, store the character */
		if (i < THRESHOLD)
		{
			storedChars[i] = c;
			i++;
		}

		/* otherwise, call the function to print the whole thing
		 * and then reset the index */
		else
		{
			printLongLine(storedChars, c);
			i = 0;
		}

		/* and if we've got a newline, we reset i as well */	
		if (c == '\n')
			i = 0;

	}


}


/* prints the character array and then keeps printing until newline */
void printLongLine(char start[], char next)
{
	int i;
	char c;

	for (i = 0; i < THRESHOLD; i++)
		putchar(start[i]);

	// print the char that told us we were over the threshold
	putchar(next);

	while ((c = getchar()) != EOF)
	{
		putchar(c);
		if (c == '\n')
			return;
	}
}
