#include "strrindex_tester.h"

/* returns the position of the rightmost match of t in s; -1 if no match */
int strrindex(char s[], char t[])
{
	int spos, tlen, i;
	char match_possible;
	spos = strlen(s) - 1;
	tlen = strlen(t);

	while (spos >= 0)
	{
		if (s[spos] == t[tlen - 1])
		{
			i = 1;
			match_possible = 1;
			while (match_possible && i < tlen)
			{
				if (s[spos - i] != t[tlen - 1 - i])
					match_possible = 0;
				i++;
			}
			if (match_possible)
				return spos + 1 - tlen;
		}
		spos--;
	}

	return -1;

}

/* strrindex() function tests */
int main()
{

	char my_str[MAX_STRLEN] = "hello world!";
	char my_search[MAX_STRLEN] = "llo";

	printf("Finding [%s] in [%s] and the position is %d.\n", my_search, my_str, strrindex(my_str, my_search));

	return 0;
}

