#include <stdio.h>

int main()
{
    int x = -1;
    if (x > 0);     //此处不应有分号，分号导致下一语句无论如何都会执行
        printf("x is positive.\n");
    return 0;
}
