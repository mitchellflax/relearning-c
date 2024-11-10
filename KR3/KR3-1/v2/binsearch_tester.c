#include "binsearch_tester.h"

int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		printf("Low is %d, mid is %d, high is %d\n",low,mid,high);
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	printf("out of loop! Low is %d, mid is %d, high is %d\n",low,mid,high);
	if (x == v[low - 1])
		return low - 1;
	else
		return -1; /* no match */

}



/* binary search function tester */
int main()
{
	/* let's make a reasonably large array to search, mults of 3 */
	int m, i, t;
	int myArray[MAX];

	m = 3;
	for (i = 0; i < MAX; i++)
	{
		myArray[i] = m;
		m += 3;
	}
	
	// we'll test with a random mult of 3
	t = 23100;
	printf("Position of t of %d in myArray is %d\n", t, binsearch(t, myArray, MAX));
	// and one non-mult of 3
	t = 532;
	printf("Position of t of %d in myArray is %d\n", t, binsearch(t, myArray, MAX));
}

