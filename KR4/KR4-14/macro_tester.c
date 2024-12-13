#include "macro_tester.h"

/* macro_tester() macro test */
int main()
{
	int a = 6;
	int b = 346;

	printf("%d, %d before swap \n", a, b);
	swap(int, a, b);
	printf("%d, %d after swap \n", a, b);

	return 0;
}

