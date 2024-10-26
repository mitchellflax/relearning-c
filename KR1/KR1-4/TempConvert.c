#include <stdio.h>

/* Print a Fahrenheit-Celsius table for conversion of every 5 degrees Celsius */

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -10;
	upper =  50;
	step = 3;

	celsius = lower;

	printf("Fahrenheit-Celsius Equivalents\n");
	printf("  C      F\n");

	while (celsius <= upper)
	{
		fahr = ((9.0/5.0) * celsius) + 32.0;
		printf("%3.0f %6.0f\n", celsius, fahr);
		celsius = celsius + step;

	}

	return 0;
}

