#include <stdio.h>

/* Print a Fahrenheit-Celsius table for conversion of every 5 degrees Celsius */

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper =  300;
	step = 3;

	celsius = lower;

	printf("Fahrenheit-Celsius Equivalents\n");
	printf("  C      F\n");

	for(fahr = upper; fahr >= lower; fahr = fahr - 10)	
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.0f\n", celsius, fahr);

	}

	return 0;
}

