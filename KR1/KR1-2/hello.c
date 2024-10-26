#include <stdio.h>

int main()
{
	printf("hello, world!");
	printf("how about a \g");
	/* cool, this throws a compile time warning, but not an error b/c the escape sequence is unknown for \g */
	/* it just prints the quoted escape */
	return 0;
}

