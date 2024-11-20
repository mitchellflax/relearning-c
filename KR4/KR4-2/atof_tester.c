#include "atof_tester.h"

/* convert string s to double, including in exponent notation */
double atof(char s[])
{
	double val, power, powermultiplier;
	int i, sign, powermultipliersign;

	for (i = 0; isspace(s[i]); i++) /* skip whitespace */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	powermultiplier = 0.0;
	powermultipliersign = 1;
	//  we need to put the power multiplier inside the 'if', otherwise we risk segfaulting if the string array was only as long as the end of the number sans an e or E
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;

		// powermultipliersign is the same as above
		// BUT remember that powermultipliersign is actually about
		// whether powermultiplier is multiplied into the numerator or denom of result
		// which is why the sign test on the return below exists
		powermultipliersign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;

		while (isdigit(s[i]))
		{
			powermultiplier = 10 * powermultiplier + (s[i] - '0');	
			i++;
		}
	}

	if (powermultipliersign == -1)
		return sign * val / (power * pow(10,powermultiplier));
	else
		return sign * val * pow(10,powermultiplier) / power;

}


/* atof() function tests */
int main()
{
	char myStr[] = "56894.23";
	char myStrE[] = "56894.23E12";
	char myStrNE[] = "56894.23e-12";


	printf("%s converted to a double is %.9f.\n", myStr, atof(myStr));
	printf("%s converted to a double is %.9f.\n", myStrE, atof(myStrE));
	printf("%s converted to a double is %.9f.\n", myStrNE, atof(myStrNE));

	return 0;
}

