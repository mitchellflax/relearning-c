#include <stdio.h>

/* only works on lines of 1000 or fewer characters */
#define LINEMAX 1000

/* reverses a string */
void reverse(char s[]);


int main()

{

	int c;
	char line[LINEMAX];
	int lineLength;

	lineLength = 0;

	while ((c = getchar()) != EOF)
	{
		/* if we hit a newline, it's time to pass to reverse and then print */
		if (c == '\n')
		{
//			printf("debug: hit newline\n");
			line[lineLength] = '\0';
			reverse(line);
			printf("%s", line);
			putchar('\n');
			lineLength = 0;
		}

		else
		{
//			printf("debug: collecting line\n");
			line[lineLength] = c;
			lineLength++;
		}
	}

	return 0;

}

/* reverses a string */
/* taking the prompt literally, we first have to find its length */
/* but of course we can just pass its length */
/* that seems cleaner... */
void reverse(char s[])
{
	int len;
	char frontEnd;
	char backEnd;
	int frontEndIndex;
	int backEndIndex;

	len = 0;
//	printf("debug: reverse fn running\n");
//	printf("debug: this is s: %s", s);

	/* find the length */	
	while (s[len] != '\0')
		len++;

	/* reverse! stop when you're still swapping front to back*/ 
	frontEndIndex = 0;
	backEndIndex = len - 1;
	while(frontEndIndex < backEndIndex)
	{
		frontEnd = s[frontEndIndex];
		backEnd = s[backEndIndex];

		s[frontEndIndex] = backEnd;
		s[backEndIndex] = frontEnd;

		frontEndIndex++;
		backEndIndex--;
	}
//	printf("debug: this is s post-reverse: %s", s);

}
