#include "decomment.h"

int main()
{
	int c, prev_char, prev_prev_char;
	// chars as booleans
	char inString, commentPossible, inMultilineComment, inLineComment;

	inString = 0;
	inMultilineComment = 0;
	inLineComment = 0;
	
	// this is really part of the test file aspect of this .c
	/* this too! */
	printf("This is a string /* and nothing should happen to the comment here or the \"thing in quotes\" */ \n");
	
	while ((c = getchar()) != EOF)
	{
		// store the previous chars for testing
		prev_prev_char = prev_char;
		prev_char = c;

		/* if you get into a string, you're not out till you close the quotes
		 * and we need to know if you're in a string because if so
		 * we're not going to stop putting the chars if we find
		 * ones that look like a comment */
		if (c == '"' && inString == 0 && prev_char != '\\')
			inString = 1;

		if (c == '"' && inString == 1 && prev_char != '\\')
			inString = 0;

		// here in the next two ifs we figure out if we're in a comment
		if (c == '/' && inString == 0)
		{
			commentPossible = 1;

			if (prev_char == '/')
			{
				// turns out we're in a comment
				// toss the last comment starter character
				inLineComment = 1;
			}

			if (prev_char == '*')
			{
				// we're exiting a comment wheeeeee
				inMultilineComment = 0;
			}
		}

		if (c == '*' && inString == 0)
		{
			if (prev_char == '/')
			{
				// turns out we're in a comment
				// toss the last comment starter character
				inMultilineComment = 1;
			}
		}

		if (c == '\n')
		{
			// if we're currently in a line comment
			// we need to actually write the newline
			if (inLineComment)
				inLineComment = 0;
		}

		// if we're not in a comment, we can put the char two chars back
		if (inMultilineComment == 0 && inLineComment == 0)
			putchar(prev_prev_char);


		// store the previous char for testing
		prev_prev_char = prev_char;
		prev_char = c;

	}

	// don't forget that last trailing char!
	putchar(prev_char);
}
