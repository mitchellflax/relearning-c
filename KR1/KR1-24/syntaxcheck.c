#include "syntaxcheck.h"

int main()
{
	// let's track all the main syntax items
	int c, prev_char, open_parens, close_parens, open_curlies, close_curlies, open_squackets, close_squackets, open_mlcomments, close_mlcomments, ticks, quotes;
	// chars as booleans
	char inString, inMultilineComment, inLineComment;

	open_parens = 0;
	close_parens = 0;
	open_curlies = 0;
	close_curlies = 0;
	open_squackets = 0;
	close_squackets = 0;
	open_mlcomments = 0;
	close_mlcomments = 0;
	ticks = 0;
	quotes = 0;

	inString = 0;
	inMultilineComment = 0;
	inLineComment = 0;
	
	// go through the file and count them	
	while ((c = getchar()) != EOF)
	{

		/* if you get into a string, you're not out till you close the quotes
		 * and we need to know if you're in a string because if so
		 * we're not counting the special chars except the unescaped quotes */
		if (c == '"' && inString == 0 && prev_char != '\\' && prev_char != '\'' && inMultilineComment == 0 && inLineComment == 0)
			inString = 1;

		else if (c == '"' && inString == 1 && prev_char != '\\' && inMultilineComment == 0 && inLineComment == 0)
			inString = 0;

		// here in the next ifs we figure out if we're in a comment
		if (c == '/' && inString == 0)
		{
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
				close_mlcomments++;
			}

			// if neither of these, it's either the *start* of a comment or not a comment
		}

		else if (c == '*' && inString == 0)
		{
			if (prev_char == '/')
			{
				// turns out we're in a comment
				inMultilineComment = 1;
				open_mlcomments++;
			}
		}

		else if (c == '\n' && inString == 0 && inLineComment)
		{
			// if we're currently in a line comment, we're not anymore
			// note that if I've done my job, we can't be inString and inLineComment, actually
			// to delete: the inString test
			inLineComment = 0;
		}

		//debugging
		// printf("c is %c, inString is %d, inLineComment is %d, inMultilineComment is %d\n", c, inString, inLineComment, inMultilineComment);

		// ok now we can use everything we've tested to decide whether to count this character

		if (c == '(' && inString == 0 && inLineComment == 0 && inMultilineComment == 0)
			open_parens++;
		if (c == ')' && inString == 0 && inLineComment == 0 && inMultilineComment == 0)
			close_parens++;
		if (c == '{' && inString == 0 && inLineComment == 0 && inMultilineComment == 0)
			open_curlies++;
		if (c == '}' && inString == 0 && inLineComment == 0 && inMultilineComment == 0)
			close_curlies++;
		if (c == '[' && inString == 0 && inLineComment == 0 && inMultilineComment == 0)
			open_squackets++;
		if (c == ']' && inString == 0 && inLineComment == 0 && inMultilineComment == 0)
			close_squackets++;
		if (c == '\'' && prev_char != '\\' && inString == 0 && inLineComment == 0 && inMultilineComment == 0)
			ticks++;
		// note that we're not going to test inString-edness for quotation marks
		if (c == '"' && prev_char != '\\' && prev_char != '\'' && inLineComment == 0 && inMultilineComment == 0)
			quotes++;

		// store the previous char for all the possible testing for comments
		prev_char = c;
	}

	/* ok now we've collected all the data and we can report out on it */

	printf("Analyzed your text file as a C program and found:\n");

	if (open_parens == close_parens)
		printf("Parentheses checks passed on %d instances.\n", open_parens);
	else
		printf("Parentheses checks failed -- %d opening parens and %d closing parens.\n", open_parens, close_parens);

	if (open_curlies == close_curlies)
		printf("Curly bracket checks passed on %d instances.\n", open_curlies);
	else
		printf("Curly bracket checks failed -- %d opening curly brackets and %d closing curly brackets.\n", open_curlies, close_curlies);

	if (open_squackets == close_squackets)
		printf("Square bracket checks passed on %d instances.\n", open_squackets);
	else
		printf("Square bracket checks failed -- %d opening square brackets and %d closing square brackets.\n", open_squackets, close_squackets);

	if (open_mlcomments == close_mlcomments)
		printf("Multiline comment checks passed on %d instances.\n", open_mlcomments);
	else
		printf("Multiline comment checks failed -- %d opening /* and %d closing */.\n", open_mlcomments, close_mlcomments);

	if (ticks % 2 != 0)
		printf("ALERT: Possible unclosed single quote ('), found %d single quotes.\n", ticks);
	if (quotes % 2 != 0)
		printf("ALERT: Possible unclosed double quote (\"), found %d double quotes.\n", quotes);

}
