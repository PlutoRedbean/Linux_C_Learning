#include <stdio.h>

int main()
{
    char a[4][3][2] = {{{'a', 'b'}, {'c', 'd'}, {'e', 'f'}},
		   {{'g', 'h'}, {'i', 'j'}, {'k', 'l'}},
		   {{'m', 'n'}, {'o', 'p'}, {'q', 'r'}},
		   {{'s', 't'}, {'u', 'v'}, {'w', 'x'}}};

    char (*pa)[2] = &a[1][0];
    char (*ppa)[3][2] = &a[1];

    // pa method
    // pa[0] == *pa指向a[1][0], (pa + 3)[0]指向a[2][0]
    printf("%c\n", (pa + 3)[2][1]);

    // ppa method
    // (ppa + 1)指向a[2]
    printf("%c\n", (*(ppa + 1))[2][1]);

    return 0;
}
