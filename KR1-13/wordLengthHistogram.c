#include <stdio.h>

#define IN	1
#define OUT 0

int main()
{
	int i, j, inp, state, currentWordLen, maxWordLen;
	currentWordLen = 0;
	state = OUT;

	/* histogram goes to 12, if there are words longer than that, they aren't going in */
	maxWordLen = 12;
	int lengthsCount[maxWordLen];

	// fill lengthsCount with zeroes
	for(i = 0; i < maxWordLen; i++)
		lengthsCount[i] = 0;
	
	/* build the array */
	while((inp = getchar()) != EOF)
	{
		/* if we're at the end of a word, store it and zero the counter */
		if(inp == ' ' || inp == '\t' || inp == '\n')
		{
			if(currentWordLen <= maxWordLen && currentWordLen > 0)
				lengthsCount[currentWordLen - 1]++;
			currentWordLen = 0;
		}

		else
			currentWordLen++;

	}

	/* print the histogram */
	for(i = 0; i < maxWordLen; i++)
	{
		// just print the index, a space, and then as many pipe chars as the num indicates 
		printf("%d\t", i+1);
		for(j = 0; j < lengthsCount[i]; j++)
			printf("|");
		printf("\n");
	}
	
	return 0;

}

