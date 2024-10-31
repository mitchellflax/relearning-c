#include "squeezetester.h"

/* implements a function to remove all chars in one string from another */
int main()
{
	char squeezed[MAX_STRLEN];
	char squeeze_out[MAX_STRLEN];

	strcpy(squeezed, "hammerbarn!");
	strcpy(squeeze_out, "barn");

	printf("Squeezing %s from %s and the result is:\n", squeeze_out, squeezed);
	squeeze(squeezed, squeeze_out);
	printf("%s\n",squeezed);

	strcpy(squeezed, "wheeeeeeEEEE!");
	strcpy(squeeze_out, "EEEEEEEEEEEEEEEEEEEEEEEEEw");

	printf("Squeezing %s from %s and the result is:\n", squeeze_out, squeezed);
	squeeze(squeezed, squeeze_out);
	printf("%s\n",squeezed);
}

/* removes all characters in s from t */
void squeeze(char s[], char t[])
{
	int i, j, scursor;
	char match_found;
	scursor = 0;
	match_found = 0;
	j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		// search t for a matching char, and if we find one, 	
		// i should advance, but scursor should not
		while (match_found == 0 && t[j] != '\0')
		{
			if (t[j] == s[i])
				match_found = 1;
			j++;
		}

		if (match_found == 0)
		{
			s[scursor] = s[i];
			scursor++;
		}

		// reset match_found and j
		match_found = 0;
		j = 0;
	}

	s[scursor] = '\0';

	return;
}
