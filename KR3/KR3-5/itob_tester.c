#include "itob_tester.h"

/* converts n into the string representation of n in base b*/
void itob(int n, char s[], int b)
{
	int i, sign, nextdigit;
	long nlong;
	nlong = n;
 
	if ((sign = n) < 0) /* record sign */
		nlong = -1 * (long) n; /* make n a long and make it positive */

	i = 0;

	do
	{
		nextdigit = nlong % b; /* get next digit */
		if (nextdigit < 10)
			s[i++] = (nlong % b) + '0'; /* use the charset 0-9 for these */
		else
			s[i++] = (nlong % b) - 10 + 'a'; /* use a-z for the next 26; fails if base 36+*/
	} while ((nlong /= b) > 0); /* delete it */

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

/* itob() function tests */
int main()
{

	char my_str[MAX_STRLEN];
	int my_int;
	int my_base;
	my_base = 16;

	my_int = -458;

	printf("Here's the integer: %d\n", my_int);
	itob(my_int, my_str, my_base);
	printf("Here it is afterward (should be the same!): %s\n", my_str);

	my_int = INT_MIN;

	printf("Here's the integer: %d\n", my_int);
	itob(my_int, my_str, my_base);
	printf("Here it is afterward (should be the same!): %s\n", my_str);

	return 0;
}

