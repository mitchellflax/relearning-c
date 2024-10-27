#include "varranges.h"

/* prints the ranges for signed and unsigned ints, shorts, longs, and chars */
int main()
{
	printf("\n*************** CHAR ***************\n");
	printf("Min for char: %d\n", CHAR_MIN);
	printf("Max for char: %d\n", CHAR_MAX);
	printf("Min for signed char: %d\n", SCHAR_MIN);
	printf("Max for signed char: %d\n", SCHAR_MAX);
	printf("Max for unsigned char: %d\n", UCHAR_MAX);

	// calculating experimentally
	char testc, testcplus1;
	testc = 0;
	testcplus1 = 1;
	while (testc < testcplus1)
	{
		testc++;
		testcplus1++;
	}

	printf("Calculated max for char is %d.\n", testc);

	printf("\n*************** INT ***************\n");
	printf("Min for int: %d\n", INT_MIN);
	printf("Max for int: %d\n", INT_MAX);
	printf("Max for unsigned int: %u\n", UINT_MAX);

	// calculating experimentally
	int testi, testiplus1;
	testi = 0;
	testiplus1 = 1;
	while (testi < testiplus1)
	{
		testi++;
		testiplus1++;
	}

	printf("Calculated max for int is %d.\n", testi);

	printf("\n*************** SHORT ***************\n");
	printf("Min for short: %d\n", SHRT_MIN);
	printf("Max for short: %d\n", SHRT_MAX);
	printf("Max for unsigned short: %d\n", USHRT_MAX);

	// calculating experimentally
	short tests, testsplus1;
	tests = 0;
	testsplus1 = 1;
	while (tests < testsplus1)
	{
		tests++;
		testsplus1++;
	}

	printf("Calculated max for short is %d.\n", tests);

	printf("\n*************** LONG ***************\n");
	printf("Min for long: %ld\n", LONG_MIN);
	printf("Max for long: %ld\n", LONG_MAX);
	printf("Max for unsigned long: %lu\n", ULONG_MAX);

	// calculating experimentally
	// assumes max must be a power of two, and if you know how bits work, well duh it has to be
	long testlong;
	testlong = 1;
	int power_of_two;
	power_of_two = 1;
	// longs are longs, so first we'll find the neighborhood, then increment by smaller steps
	while (testlong < testlong * pow(2, power_of_two))
		power_of_two++;
	testlong = testlong * pow(2, power_of_two - 1);

	printf("Calculated max for long is %ld.\n", testlong);
	printf("That's 2 ^ %d power.",power_of_two - 1);
}
