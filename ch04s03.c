#include <stdio.h>

void first(int x)
{
    if (x > 0 && x < 10);
    else
        printf("x is out of range.\n");
    
    if (x <= 0 || x >= 10)
        printf("x is out of range.\n");
}

void second(int x, int y)
{
    if (x > 0)
        printf("Test OK!\n");
    else if (x <= 0 && y > 0)
        printf("Test OK!\n");
    else
        printf("Test failed!\n");

    if (x <= 0 && y <= 0)
        printf("Test failed!\n");
    else
        printf("Test OK!\n");
}

void third(int x, int y)
{
    if (x > 1 && y != 1) {
        printf("1\n");
    } else if (x < 1 && y != 1) {
        printf("2\n");
    } else {
        printf("3\n");
    }

    if (x > 1 && y != 1) {
        printf("1\n");
    } else if (x < 1 && y != 1) {
        printf("2\n");
    } else if (x == 1) {    //错误，应为x == 1 || y == 1
        printf("3\n");
    }

}

void forth(int x, int y, int z)
{
    if (x < 3 && y > 3)
        printf("Test OK!\n");
    else if (x >= 3 && y >= 3)      //可删除
        printf("Test OK!\n");
    else if (z > 3 && x >= 3)
        printf("Test OK!\n");
    else if (z <= 3 && y >= 3)
        printf("Test OK!\n");
    else
        printf("Test failed!\n");
}

int main()
{
    int x = 567;
    printf("unit: %d\n", unit(x));
    printf("tens: %d\n", tens(x));
    return 0;
}
