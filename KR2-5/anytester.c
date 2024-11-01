#include "anytester.h"

/* implements a function to report the index of the first instance of a char in one string inside another */
int main()
{
	char searched[MAX_STRLEN];
	char search_chars[MAX_STRLEN];

	strcpy(searched, "hammerbarn!");
	strcpy(search_chars, "barn");

	printf("Finding %s from %s and the result index is %d.\n", search_chars, searched, any(searched, search_chars));

	strcpy(searched, "hello!");
	strcpy(search_chars, "gbrd?");

	printf("Finding %s from %s and the result index is %d.\n", search_chars, searched, any(searched, search_chars));

	strcpy(searched, "the worlddddddd");
	strcpy(search_chars, "d");

	printf("Finding %s from %s and the result index is %d.\n", search_chars, searched, any(searched, search_chars));
}

/* removes all characters in s from t */
int any(char s[], char t[])
{
	int i, j;
	j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; t[j] != '\0'; j++)
			if (t[j] == s[i])
				return i;
	}

	return -1;
}
