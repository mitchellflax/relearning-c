#include "tabsToSpaces.h"

/* for every TAB_LENGTH spaces, replace tabs and  
 * create tabstops from only spaces */
int main()
{
	int c, cursor, spacesToPut, i;

	cursor = 0;

	while ((c = getchar()) != EOF)
	{
		if (c != '\t' && c != '\n')
		{
			putchar(c);
			cursor++;
		}

		else if (c == '\n')
		{
			putchar(c);
			cursor = 0;	
		}

		else if (c == '\t')
		{
			spacesToPut = (TAB_LENGTH - (cursor % TAB_LENGTH));
			for (i = 0; i < spacesToPut; i++)
				putchar(' ');
		}

	}

}
