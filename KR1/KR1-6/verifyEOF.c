#include <stdio.h>

/* print the output of the expression getchar() != EOF */
int main()
{
	int myVar = getchar() != EOF;
	printf("%d is the value of getchar() != EOF", getchar() != EOF);

	return 0;
}

