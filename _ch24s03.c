#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int number;
	char *msg;
} unit_t;

unit_t *alloc_unit(unit_t *p)
{
	p = malloc(sizeof(unit_t));
	if (p == NULL) {
		exit(1);
	}
	p->number = 3;
	p->msg = malloc(100);
	strcpy(p->msg, "Hello");
	return p;
}

void free_unit(unit_t *p)
{
	free(p->msg);
	free(p);
}

int main(void)
{
	static unit_t *p = NULL;

	p = alloc_unit(p);
	printf("number: %d\nmsg: %s\n", p->number, p->msg);
	free_unit(p);
	p = NULL;
	return 0;
}
