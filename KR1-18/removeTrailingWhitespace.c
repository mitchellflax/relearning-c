#include <stdio.h>

/* if the whitespace anywhere on a line is bigger than this
 * the program fails and not gracefully */
#define BUFFERSIZE 100

void dumpBuffer(int myBuff[], int numChars);

/* remove all trailing whitespace after lines
 * plus blank lines */
int main()
{
	int charsIntoLine;
	int charsIntoWhitespace;
	int c;
	int buffer[BUFFERSIZE];

	charsIntoLine = 0;
	charsIntoWhitespace = 0;
	
	/* read chars; if they're non-whitespace, send to output
	 * if they're whitespace, load them into a buffer */
	while ((c = getchar()) != EOF)
	{
		/* tabs, spaces, and newlines will get special handling */
		if (c != '\t' && c != ' ' && c != '\n')
		{
			/* dump the buffer when we hit non-whitespace */
			if (charsIntoWhitespace > 0)
			{
				dumpBuffer(buffer, charsIntoWhitespace);
				charsIntoWhitespace = 0;
			}
			putchar(c);
			charsIntoLine++;
		}

		/* if we hit a newline at the start of the line, just move on */
		/* but if we hit a newline elsewhere, just reset the buffer/whitespace counter */
		else if (c == '\n' && charsIntoLine == 0)
		{
			;	
		}

		else if (c == '\n')
		{
			putchar(c);
			charsIntoLine = 0;
			charsIntoWhitespace = 0;
		}

		/* at this point it's got to be tabs and spaces */
		else
		{
			charsIntoLine++;
			buffer[charsIntoWhitespace] = c;
			charsIntoWhitespace++;
		}

	} 

	return 0;

}

void dumpBuffer(int myBuff[], int numChars)
{
	int i;
	
	for (i = 0; i < numChars; i++)
		putchar(myBuff[i]);

}
