#include <stdio.h>

/* changes tabs to \t, backspaces to \b, and backslashes to \\ */
/* this doesn't work for backspace because modern systems don't pass backspace as a char */
/* which I learned trying to debug this */
/* theeee moooooree youuuuuu knowwwwww */
int main()
{
	int currentChar; 

	while((currentChar = getchar()) != EOF)
	{
		if(currentChar == '\t')
		{
			putchar('\\');
			putchar('t');
		}

		else if(currentChar == '\b')
		{
			putchar('\\');
			putchar('b');
			printf("backspace!");
		}

		else if(currentChar == '\\')
		{
			putchar('\\');
			putchar('\\');
		}

		else
			putchar(currentChar);

	}

	return 0;

}
