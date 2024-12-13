#include "reverse_tester.h"

/* reverses the string */
void reverse(char s[], int startInd, int endInd)
{
	char c;

	if (startInd != endInd)
	{
		c = s[startInd];
		s[startInd] = s[endInd];
		s[endInd] = c;
		reverse(s, ++startInd, --endInd);
	}

	return;

}


/* reverse() function test */
int main()
{
	char myStr[] = "hello, world!";

	printf("%s is the original string.\n", myStr);
	reverse(myStr, 0, strlen(myStr) - 1);
	printf("%s is the reversed string.\n", myStr);

	return 0;
}

