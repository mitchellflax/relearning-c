#include "entab.h"

/* replaces strings of whitespace with strings of min req'd tabs + spaces */
int main()
{
	int c, cursor, whitespaceAccumulated, whitespaceToAdd;

	cursor = 0;
	whitespaceAccumulated = 0;
	whitespaceToAdd = 0;

	while ((c = getchar()) != EOF)
	{
		/* if we're accumulating whitespace, pause the cursor
		 * and add up the whitespace
		 * until we come to non-whitespace;
		 * then we cash out that whitespace before putting the char
		 * and move up the cursor the right number of spaces */
		if (c == ' ')
			whitespaceAccumulated++;

		else if (c == '\t')
		{
			whitespaceAccumulated += (TAB_LENGTH - (cursor % TAB_LENGTH));
		}

		else if (c == '\n')
		{
			cursor = 0;
			whitespaceAccumulated = 0;
			putchar(c);
		}

		else
		{
			// neither of these loops happen if no whitespace accumulated
			while (whitespaceAccumulated > TAB_LENGTH)
			{
				putchar('\t');
				whitespaceToAdd = TAB_LENGTH - (cursor % TAB_LENGTH);
				cursor += whitespaceToAdd;
				whitespaceAccumulated -= whitespaceToAdd;
			}

			while (whitespaceAccumulated > 0)
			{
				putchar(' ');
				whitespaceAccumulated--;
				cursor++;
			}

			// don't forget to put the non-whitespace character!
			putchar(c);	
			cursor++;
		}
		

	}

}

