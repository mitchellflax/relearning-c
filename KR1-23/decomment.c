#include "decomment.h"

int main()
{
	int c, prev_char;
	// chars as booleans
	char inString, commentPossible, inMultilineComment, inLineComment;

	inString = 0;
	inMultilineComment = 0;
	inLineComment = 0;
	commentPossible = 0;
	
	// this is really part of the test file aspect of this .c
	/* this too! */
	printf("This is a string /* and nothing should happen to the comment here or the \"thing in quotes\" */ \n\n\n");
	
	while ((c = getchar()) != EOF)
	{

		/* if you get into a string, you're not out till you close the quotes
		 * and we need to know if you're in a string because if so
		 * we're not going to stop putting the chars if we find
		 * ones that look like a comment */
		// printf("\nstring test: %d, %d, %d\n", c == '"', inString == 0, prev_char != '\\');
		/* note we have to test here if we're already in a comment
		 * and not bother with string testing if we are
		 * because the quotation mark rules stop within a comment */
		if (c == '"' && inString == 0 && prev_char != '\\' && inMultilineComment == 0 && inLineComment == 0)
			inString = 1;

		else if (c == '"' && inString == 1 && prev_char != '\\' && inMultilineComment == 0 && inLineComment == 0)
			inString = 0;

		// here in the next ifs we figure out if we're in a comment
		if (c == '/' && inString == 0)
		{
			commentPossible = 1;

			if (prev_char == '/')
			{
				// turns out we're in a comment
				// toss the last comment starter character
				inLineComment = 1;
			}

			else if (prev_char == '*')
			{
				// we're exiting a comment wheeeeee
				inMultilineComment = 0;
			}

			// it's either the *start* of a comment or not a comment
			else
				putchar(prev_char);
		}

		else if (c == '*' && inString == 0)
		{
			if (prev_char == '/')
			{
				// turns out we're in a comment
				inMultilineComment = 1;
			}
		}

		else if (c == '\n' && inString == 0)
		{
			// if we're currently in a line comment
			// we need to actually write the newline
			if (inLineComment)
				inLineComment = 0;
			commentPossible = 0;
		}

		else
			commentPossible = 0;

		// if we're not in a comment or possibly in a comment, we can put the char
		if (inMultilineComment == 0 && inLineComment == 0 && commentPossible == 0)
			putchar(c);
		// if none of those are true AND if we're in a string, then we do want to put the char
		else if (inString == 1)
			putchar(c);

		// printf("\nDebug: c is %c, prev_char is %c, commentPossible is %d, inLineComment is %d, inMultilineComment is %d, inString is %d\n", c, prev_char, commentPossible, inLineComment, inMultilineComment, inString);

		// store the previous char for putting it if appropriate
		prev_char = c;

	}
}
