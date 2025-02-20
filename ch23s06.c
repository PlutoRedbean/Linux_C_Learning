#include <stdio.h>

int main(void)
{
	typedef char *string;

	string a = "a", b = "b", c = "c";
	
	const char **pa = &a;
	**pa = 'b';
	*pa = b;
	pa = &b;
	
	char *const *pb = &b;
	**pb = 'c';
	*pb = c;
	pb = &c;

	char **const pc = &c;
	**pc = 'a';
	*pc = a;
	pc = &a;

	return 0;
}
