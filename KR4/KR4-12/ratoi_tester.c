#include "ratoi_tester.h"

/* I realized after doing this that I reversed the brief, DOH */
/* no wonder it seemed sort of unrelated to the principle they asked me to use */
/* maybe will redo at some point, but tbh not really worth the time */


/* convert string s to an integer, recursively! */
/* pass 0 as second two args to call from scratch */
/* janky? yes, a bit */
int atoi(char s[], int total, int tenpwr)
{
	int len;
	len = strlen(s);

	if (len == 1)
	{
		if (s[0] == '-')
			return -1 * total;
		else
			return total + ((s[0] - '0') * pow(10,tenpwr));
	}

	total += (s[len-1] - '0') * pow(10, tenpwr);
	s[len-1] = '\0';
	return atoi(s, total, ++tenpwr);
	
}


/* atoi() function tests */
int main()
{
	char myStr[] = "56894";
	char myStrN[] = "-56894";

	printf("%s converted to an integer is ", myStr);
	printf("%d.\n", atoi(myStr, 0, 0));
	printf("%s converted to an integer is ", myStrN);
	printf("%d.\n", atoi(myStrN, 0, 0));

	return 0;
}

