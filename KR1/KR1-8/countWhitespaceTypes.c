#include <stdio.h>

/* counts and prints all blanks (spaces), tabs, and newlines */
int main()
{
	int nc, spaces, tabs, nls;

	spaces = 0;
	tabs = 0;
	nls = 0;

	while((nc = getchar()) != EOF)
	{
		if(nc == ' ')
			spaces++;

		if(nc == '\t')
			tabs++;

		if(nc == '\n')
			nls++;
	}

	printf("%d spaces, %d tabs, %d newlines\n", spaces, tabs, nls);

	return 0;

}
