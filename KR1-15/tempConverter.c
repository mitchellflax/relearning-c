#include <stdio.h>

int convertFtoC(int fahr);

int main()
{
	int fahrenheit, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahrenheit = lower;
	while (fahrenheit <= upper)
	{
		celsius = convertFtoC(fahrenheit);
		printf("%d\t%d\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + step;
	} 

	return 0;

}

int convertFtoC(int fahr)
{
	int cels;
	cels = (5 * (fahr - 32)) / 9;
	return cels;
}

