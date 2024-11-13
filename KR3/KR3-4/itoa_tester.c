#include "itoa_tester.h"

/* converts n into the string representation of n */
/* unlike the version in K&R, works for the maximal neg value in two's complement */
void itoa(int n, char s[])
{
	int i, sign;
	long nlong;
	nlong = n;
 
	/* It's kind of a cheat to make this work for the INT_MIN n
	 * by just using a long for the two's complement.
	 * But it works! The problem in K&R's version is literally
	 * that there aren't enough available bits; the INT_MAX is a smaller #
	 * than -1 * INT_MIN because the first bit in a two's complement system
	 * has to be 0 for a positive integer;
	 * There are probably more elegant ways to do this, as well as even dirtier ones
	 * (hardcoding it in comes to mind)
	 * but this works. */
	if ((sign = n) < 0) /* record sign */
		nlong = -1 * (long) n; /* make n a long and make it positive */

	i = 0;

	do
	{
		s[i++] = nlong % 10 + '0'; /* get next digit */
	} while ((nlong /= 10) > 0); /* delete it */

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

	return;
}

/* reverses a string s in place */
void reverse(char s[])
{
	int low, high, holder;

	high = strlen(s) - 1;
	
	for (low = 0; low < high; low++, high--)
	{
		holder = s[low];
		s[low] = s[high];
		s[high] = holder;
	}

	return;
}

/* expand() function tests */
int main()
{

	char my_str[MAX_STRLEN];
	int my_int;

	my_int = -458;

	printf("Here's the integer: %d\n", my_int);
	itoa(my_int, my_str);
	printf("Here it is afterward (should be the same!): %s\n", my_str);

	my_int = INT_MIN;

	printf("Here's the integer: %d\n", my_int);
	itoa(my_int, my_str);
	printf("Here it is afterward (should be the same!): %s\n", my_str);

	return 0;
}

