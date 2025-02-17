#include <stdio.h>

int main()
{
    int a[5] = { 0, 1, 2, 3, 4 }, b[5];
    for (int i = 0; i < 5; i++) {
        b[i] = a[i];
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
}
