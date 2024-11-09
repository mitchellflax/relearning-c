// rewriting a for loop that used logical operators with only arithmetic
//
// original:
//
for (i = 0; i < lim - 1 && (c = getchar()) != \n && c != EOF; ++i)
	s[i] = c;
// mod:
//
for (i = 0; (i < lim - 1) + ((c = getchar()) != \n) + (c != EOF) == 3; ++i)
	s[i] = c;
