#include "fold.h"

void putBuffer(char buffer[], int startIndex, int endIndex)
{
	// no error checking, clear eyes full heart can't segfault
	int i;

	for(i = startIndex; i < endIndex; i++)
		putchar(buffer[i]);

}

int main()
{
	int c, cursor, lastblank, i;
	char line_buffer[MAX_LINE_CHARS];

	cursor = 0;
	lastblank = 0;

	while ((c = getchar()) != EOF)
	{
		// keep track of where we find the last blank before the cursor
		if (c == ' ' || c == '\t')
			lastblank = cursor;

		// if the buffer is full OR we get to a newline, dump the buffer to output
		// TODO NEXT: THE FULL BUFFER PART IS DONE, THE NEWLINE PART IS NOT; NEED TO RETHINK THE FLOW HERE
		if (cursor == (MAX_LINE_CHARS -1) || c == '\n')
		{
			// write up to the last blank
			putBuffer(line_buffer, 0, lastblank - 1);

			// reset the cursor
			cursor = MAX_LINE_CHARS - lastblank

			// write a newline and then bring whatever we didn't write to the front of the buffer
			putchar('\n');
			for (i = 0; i < cursor; i++)
				line_buffer[i] = line_buffer[lastblank + i];

			// reset the lastblank 
			lastblank = cursor;
		}

		// ok let's actually store the line; this is all that happens on the median character read
		line_buffer[cursor] = c;
		cursor++;

	}

}
