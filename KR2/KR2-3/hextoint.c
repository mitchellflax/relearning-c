#include "hextoint.h"

/* implements a function for a hex string conversion to an integer */
int main()
{
	printf("5c6 in hex is %d in decimal\n",htoi("5c6"));
	printf("0x5c6 in hex is %d in decimal\n",htoi("0x5c6"));
	printf("0X5c6 in hex is %d in decimal\n",htoi("0X5c6"));
	printf("f115c6 in hex is %d in decimal\n",htoi("f115c6"));

	printf("The following should cause an error and a return value of -1.\n");
	printf("y115c6 in hex is %d in decimal\n",htoi("y115c6 "));

}

/* takes a number as hex and returns the equivalent int */
int htoi(char s[])
{
	int len, power, startIndex, i, runningTotal, hexDigit;
	len = strlen(s);
	power = len - 1;
	startIndex = 0;
	runningTotal = 0;

	// do we have a leading "0x"? if so, we need to account for it
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		power = len - 3;
		startIndex = 2;
		printf("we have a leading 0x or 0X, power is %d, len is %d\n", power, len);
	}
	
	for (i = startIndex; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			hexDigit = s[i] - '0';

		else if (s[i] >= 'a' && s[i] <= 'f')
			hexDigit = 10 + (s[i] - 'a');

		else if (s[i] >= 'A' && s[i] <= 'F')
			hexDigit = 10 + (s[i] - 'F');

		else
		{
			printf("ERROR, non-conformant char provided in string\n");
			return -1;
		}

		runningTotal += hexDigit * pow(16,power);
		power--;

	}

	return runningTotal;
}
