#include <stdio.h>
#include <math.h>

int GCD(int, int);

int fib(int);

int GCD(int a, int b)
{
    if (a % b == 0) {
        return b;
    }
    return GCD(b, a % b);
}

int fib(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int a, b, n;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    printf("Input n: ");
    scanf("%d", &n);
    printf("GCD: %d\n", GCD(a, b));
    printf("fib(%d) = %d\n", n, fib(n));

    return 0;
}
