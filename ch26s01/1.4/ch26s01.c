#include <stdio.h>
#include "circlelinkedlist.h"

int main(void)
{
    int n, m;
    printf("input n: ");
    scanf("%d", &n);
    printf("input m: ");
    scanf("%d", &m);
    josephus(n, m);

	return 0;
}
