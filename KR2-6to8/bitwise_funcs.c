#include "bitwise_funcs.h"

/* sets the n bits from bit position p in x to the n rightmost bits of y */
int setbits(int x, int p, int n, int y)
{
	int xmask, ymask;
	int i;

	/* ymask */
	// mask off the correct number of bits of y, then shift left by p
	ymask = 0;
	for (i = 0; i < n; i++)
		ymask += pow(2,i);

	// mask off the correct number of bits of y	
	ymask = y & (int) ymask;

	// bitshift y by p digits
	ymask = ymask << p;

	/* xmask */
	// mask off the x bits from bit positions p to p + (n-1)
	xmask = 0;
	for (i = p; i < p + n; i++)
		xmask += pow(2,i);

	// then mask the inverse of that from x
	// to get only the non-subbed bits into the x-mask
	xmask = x & ~xmask;

	/* put it together */
	return xmask | ymask;
}

int invert(int x, int p, int n)
{
	int keepmask, invertmask, positionbits, i;
	
	/* keepmask */
	// mask off the x bits from bit positions p to p + (n-1)
	positionbits = 0;
	for (i = p; i < p + n; i++)
		positionbits += pow(2,i);

	// then mask the inverse of that from x
	// to get only the non-subbed bits into the x-mask
	keepmask = x & ~positionbits;

	/* invertmask */
	invertmask = x & positionbits;
	invertmask = ~invertmask;
	// now we need to mask out the bits before and after the positionbits
	invertmask = invertmask & positionbits;

	return (keepmask | invertmask);	

}

int rightrot(int x, int n)
{
	// store the rightmost n bits
	int i, positionbits, rightnstore;

	positionbits = 0;
	for (i = 0; i < n; i++)
		positionbits += pow(2,i);

	rightnstore = x & positionbits;
	rightnstore = rightnstore << (CHAR_BIT*sizeof(int) - n);

	x = x >> n;

	return (rightnstore | x);

}

/* implements and tests bitwise operation functions */
int main()
{
	// test setbits
	int myx, myy, myp, myn;

	myx = 25;
	myy = 58;
	myp = 2;
	myn = 4;

	printf("\nTesting setbits() function:\n");
	printf("My x is %d, my y is %d, using p of %d and n of %d\n", myx, myy, myp, myn);
	myx = setbits(myx, myp, myn, myy);
	printf("The resulting setbits() transformation of x is %d.\n", myx);


	// test invert
	myx = 429;
	myp = 3;
	myn = 4;

	printf("\nTesting invert() function:\n");
	printf("My x is %d, using p of %d and n of %d\n", myx, myp, myn);
	myx = invert(myx, myp, myn); 
	printf("The resulting invert() transformation of x is %d.\n", myx);

	// test rightrot
	myx = 1479;
	myn = 4;

	printf("\nTesting rightrot() function:\n");
	printf("My x is %d, using n of %d\n", myx, myn);
	myx = rightrot(myx, myn);
	printf("The resulting rightrot() transformation of x is %d.\n", myx);

}

