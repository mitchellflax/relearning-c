#include "polishcalc.h"

/* push: push f onto the value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* not a number */
	i = 0;
	/* collect integer part */
	while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect faction part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	printf("s is %s\n", s);
	if (c != EOF)
		ungetch(c);

	return NUMBER;

}

int getch(void) /* get a (possibly pushed back) character */
{
	 return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}


/* the reverse Polish calculator! not as tasty as the reverse Polish pierogi */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{

		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			push( (int) pop() % (int) op2); /* discards numbers after decimal if you feed it a float */
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
			}
	}

	return 0;
}
