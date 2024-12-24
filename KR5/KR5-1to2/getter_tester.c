#include "getter_tester.h"

int getch(void) /* get a (possibly pushed back) character */
{
	 return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch())) /* skip whitespace */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c); /* it's not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();

	/* tests if an actual digit comes after the sign */
	if (!isdigit(c))
	{
		ungetch(c);
		if (sign == -1)
			ungetch('-');
		else
			ungetch('+');
		return 0;
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}

/* getint: get next integer from input into *pn */
int getfloat(float *pf)
{
	int c, sign, power;
	power = 1.0;

	while (isspace(c = getch())) /* skip whitespace */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c); /* it's not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();

	/* tests if an actual digit comes after the sign */
	if (!isdigit(c))
	{
		ungetch(c);
		if (sign == -1)
			ungetch('-');
		else
			ungetch('+');
		return 0;
	}

	for (*pf = 0; isdigit(c); c = getch())
		*pf = 10 * *pf + (c - '0');

	if (c == '.')
	{
		for (c = getch(); isdigit(c); c = getch())
		{
			printf("*pf is %f, c is %d\n",*pf, c);
			*pf = (10 * *pf) + (c - '0');
			printf("*pf is %f\n",*pf);
			power *= 10;
		}
	}

	printf("*pf is %f, sign is %d, power is %d\n",*pf, sign, power);


	*pf *= (((float) sign) / ((float) power));

	if (c != EOF)
		ungetch(c);

	return c;
}

/* tests getint and getfloat */
int main()
{
	int myint;
	myint = 5;

	printf("enter an int to stdin\n");
	getint(&myint);

	printf("myint is now %d\n", myint);

	float myfloat;
	myfloat = 3.682;

	printf("enter a float to stdin\n");
	getfloat(&myfloat);

	printf("myfloat is now %f\n", myfloat);

	return 0;
}
