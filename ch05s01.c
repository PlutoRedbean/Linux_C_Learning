#include <stdio.h>
#include <math.h>

int is_leap_year(int year);

double myround(double x);

int is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

double myround(double x)
{
    if (x >= 0) {
        return (x - floor(x) >= 0.5) ? ceil(x) : floor(x);
    } else {
        return ((-x) - (-ceil(x)) >= 0.5) ? floor(x) : ceil(x);
    }
}

int main()
{
    int year;
    double num;
    printf("input year: ");
    scanf("%d", &year);
    printf("input number: ");
    scanf("%lf", &num);
    if (is_leap_year(year)) {
        printf("\nIt is leap year!\n");
    } else {
        printf("\nIt is not leap year!\n");
    }

    printf("Round number: %lf\n", myround(num));

    return 0;
}
