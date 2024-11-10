#include "escape_tester.h"

void escape(char s[], char t[])
{
	int scursor, tcursor;
	scursor = 0;
	tcursor = 0;

	while (t[tcursor] != '\0')
	{
		switch (t[tcursor])
		{
			case '\t':
				s[scursor] = '\\';
				scursor++;
				s[scursor] = 't';
				break;
			case '\n':
				s[scursor] = '\\';
				scursor++;
				s[scursor] = 'n';
				break;
			case '\b':
				s[scursor] = '\\';
				scursor++;
				s[scursor] = 'b';
				break;
			case '\r':
				s[scursor] = '\\';
				scursor++;
				s[scursor] = 'r';
				break;
			
			default:
				s[scursor] = t[tcursor];
				break;
		}

		scursor++;
		tcursor++;

	}
	s[scursor] = '\0';
	return;
}

void unescape(char s[], char t[])
{
	int scursor, tcursor;
	scursor = 0;
	tcursor = 0;

	while (t[tcursor] != '\0')
	{
		if (t[tcursor] != '\\')
			s[scursor] = t[tcursor];
		else
			switch (t[tcursor+1])
			{
				case 't':
					s[scursor] = '\t';
					tcursor++;
					break;
				case 'n':
					s[scursor] = '\n';
					tcursor++;
					break;
				case 'b':
					s[scursor] = '\b';
					tcursor++;
					break;
				case 'r':
					s[scursor] = '\r';
					tcursor++;
					break;
				
				default:
					s[scursor] = t[tcursor];
					break;
			}

		scursor++;
		tcursor++;
	}
	s[scursor] = '\0';
	return;
}

/* escape() and unescape() function tests */
int main()
{

	char my_str[MAX_STRLEN] = "Hello			I'm a string!\n\n\nAnd I have some tabs.\n";
	char my_copy_str[MAX_STRLEN];

	printf("Here's my_str before escaping:\n%s\n", my_str);
	escape(my_copy_str, my_str);
	printf("Here it is afterward:\n%s\n",my_copy_str);

	// setting up the test in reverse
	strcpy(my_str, my_copy_str);

	printf("Here's my_str before un-escaping:\n%s\n", my_str);
	unescape(my_copy_str, my_str);
	printf("Here it is afterward:\n%s\n",my_copy_str);
	
}

