#include <stdio.h>

/* verify that the expression getchar() != EOF is either 1 or 0 */
int main()
{
	int c;

	printf("Here's the output:\n");
	printf("%d\n",getchar() != EOF);

	return 0;
}

