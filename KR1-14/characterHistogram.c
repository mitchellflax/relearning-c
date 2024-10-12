#include <stdio.h>

int main()
{
	int i, j, inp, maxChar;

	/* histogram is built for 8-bit chars, throws error from out-of-index array if no dice */
	maxChar = 256;
	int charRegister[maxChar];

	// fill charRegister with zeroes
	for(i = 0; i < maxChar; i++)
		charRegister[i] = 0;
	
	/* build the array */
	while((inp = getchar()) != EOF)
		charRegister[inp]++;

	/* print the histogram */
	for(i = 0; i < maxChar; i++)
	{
		// just print the index as num, a tab, the index as char, and then as many pipe chars as the num indicates 
		printf("%d\t%c\t",i,i);
		for(j = 0; j < charRegister[i]; j++)
			printf("|");
		printf("\n");
	}
	
	return 0;

}

