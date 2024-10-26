#include <stdio.h>

/* shortens every set of spaces to a single space */
int main()
{
	int currentChar; 

	while((currentChar = getchar()) != EOF)
	{
		if(currentChar != ' ')
			putchar(currentChar);

		else
		{

			while((currentChar = getchar()) != EOF && currentChar == ' ')
			{
				;
			}
			putchar(' ');
			putchar(currentChar);

		}

	}

	return 0;

}
