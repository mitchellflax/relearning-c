#include "bitcount_tester.h"

/* counts the number of '1' bits in the binary representation of x */
/* is supposed to be faster i.e. do less than bitcount() in K&R */
int bitcount (unsigned x)
{
	/* First, an explanation of why x &= (x-1) deletes the rightmost 1 bit
	 * in the two's complement representation of an integer.
	 *
	 * If x is odd, its bit in the rightmost position for 2^0 is 1.
	 * If x is odd, x-1 is even and identical to x except that the 2^0 position is 0.
	 * >> x & (x-1) yields identical bits except in the rightmost position,
	 * which becomes 0.
	 *
	 * If x is even, its rightmost bit is 0.
	 * If another bit is 1, if x is negative or if x is nonzero, 
	 * then given that the rightmost '1' bit is in the 2^n position of x
	 * then (x-1) contains a '0' bit in the 2^n position and '1' bits in positions
	 * 2^(n-1) ... 2^0. The & operation of the 0s in x from the 2^(n-1) position
	 * and the 1s in (x-1) from the same position all yield 0 in the (x & (x-1)) operation.
	 * Likewise, the 1 in x's 2^n position and the 0 in (x-1)'s 2^n position yields 0.
	 * >> x & (x-1) yields identical bits except in the rightmost position, which becomes 0.
	 *
	 * So we can yield a faster version of bitcount simply
	 * by executing x &= x-1 until x == 0. */

	int b;
	b = 0;

	while (x != 0)
	{
		x &= (x - 1);
		b++;
	}

	return b;
}

/* implements a faster version of the bitcount() function */
int main()
{
	unsigned x;

	x = 59;
	printf("The number of 1 bits in %d is %d.\n",x,bitcount(x));
	x = -33;
	printf("The number of 1 bits in %d is %d.\n",x,bitcount(x));
	x = 44;
	printf("The number of 1 bits in %d is %d.\n",x,bitcount(x));
	x = 123412333;
	printf("The number of 1 bits in %d is %d.\n",x,bitcount(x));
	x = -985523426;
	printf("The number of 1 bits in %d is %d.\n",x,bitcount(x));
}

