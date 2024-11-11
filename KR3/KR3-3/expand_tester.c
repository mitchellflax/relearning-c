#include "expand_tester.h"

/* copies s2 into s1, expanding any a-z or 0-9 ranges like b-k to bcd...ijk */
void expand(char s1[], char s2[])
{
	int s2cursor, s1cursor;
	char startrange, endrange;
	s2cursor = 0;
	s1cursor = 0;

	while (s2[s2cursor] != '\0')
	{
		if (s2[s2cursor] == '-' )
		{
			// no range if it's a leading or trailing dash
			if (s2cursor == 0 || s2[s2cursor+1] == '\0')
				s1[s1cursor] = s2[s2cursor];
			
			else
			{
				// we've already copied the starting character, so we need to start one further (e.g. if it's 2-7, we've already copied 2, so copy 3 now)
				startrange = s2[s2cursor - 1] + 1;
				endrange = s2[s2cursor + 1];
				while (startrange <= endrange)
				{
					s1[s1cursor] = startrange;
					startrange++;
					s1cursor++;
				}

				s2cursor++;
			}
				
		}

		else
		{
			s1[s1cursor] = s2[s2cursor];
			s1cursor++;
		}

		s2cursor++;	
	}

	s1[s1cursor] = '\0';
	return;
}

/* expand() function tests */
int main()
{

	char my_str[MAX_STRLEN] = "a-q6-9f-z0-3-5-";
	char my_expanded_str[MAX_STRLEN];

	printf("Here's my_str before expanding:\n%s\n", my_str);
	expand(my_expanded_str, my_str);
	printf("Here it is afterward:\n%s\n", my_expanded_str);
}

