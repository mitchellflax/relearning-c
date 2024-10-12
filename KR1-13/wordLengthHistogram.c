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
		// debugging
		printf("inp: %c\n", inp);
		printf("currentWordLen before eval: %d\n", currentWordLen);

		/* if we're at the end of a word, store it and zero the counter */
		if(inp == ' ' || inp == '\t' || inp == '\n')
		{
			if(currentWordLen <= maxWordLen && currentWordLen > 0)
				lengthsCount[currentWordLen - 1]++;
			currentWordLen = 0;
		}

		else
			currentWordLen++;

		//debugging
		printf("currentWordLen after eval: %d\n", currentWordLen);

		//debug what's in array?
		for(i =0; i < maxWordLen; i++)
		{
			printf(" %d", lengthsCount[i]);
		}
		printf("\n");

	}

	/* array debug

	for(i =0; i < maxWordLen; i++)
	{
		printf(" %d", lengthsCount[i]);
	}
	*/


	/* print the histogram */
	/* for now just the array */
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

