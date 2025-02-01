#include <stdio.h>
#include <math.h>

int min(int, int);
int GCD(int, int);
int fib(int);
int unit(int);
int tens(int);
int nine_counter();

int min(int a, int b)
{
    return a > b ? b : a;
}

int GCD(int a, int b)
{
    int result = 1;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            result = i;
        }
    }
    return result;
}

int fib(int n)
{
    int result = 1, result_1 = 1, result_2 = 1;
    for (int i = 3; i <= n; i++) {
        result = result_1 + result_2;
        result_2 = result_1;
        result_1 = result;
    }
    return result;
}

int unit(int num)
{
    int temp = num / 10;
    return num - temp * 10;
}

int tens(int num)
{
    return unit(num / 10);
}

int nine_counter()
{
    int result = 0;
    for (int i = 1; i <= 100; i++) {
        if (unit(i) == 9) {
            result += 1;
        }
        if (tens(i) == 9) {
            result += 1;
        }
    }
    return result;
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
    printf("9 times from 1 to 100: %d\n", nine_counter());

    return 0;
}
