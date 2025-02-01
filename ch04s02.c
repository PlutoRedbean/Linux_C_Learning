#include <stdio.h>

int unit(int);
int tens(int);

int unit(int num)
{
    int temp = num / 10;
    return num - temp * 10;
}

int tens(int num)
{
    return unit(num / 10);
}

int main()
{
    int x = 567;
    printf("unit: %d\n", unit(x));
    printf("tens: %d\n", tens(x));
    return 0;
}
