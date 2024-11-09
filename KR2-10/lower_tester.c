#include "lower_tester.h"

/* convert c to lowercase; ASCII only */
int lower(int c)
{
	c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
	return c;
}

/* lower() function tests */
int main()
{
	printf("All of the following sentence should emerge lowercase on next line: HI wORld!\n%c%c%c%c%c%c%c%c\n",lower('H'),lower('I'),lower(' '),lower('w'),lower('O'),lower('R'),lower('l'),lower('d'));
}

