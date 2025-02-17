#include <stdio.h>

#define LEN 8
int a[LEN] = { 1, 1, 2, 2, 5, 5, 5, 9 };
int count = 0;

int binarysearch(int start, int end, int number)
{
	int mid;
	if (start <= end) {
		mid = (start + end) / 2;
		if (number < a[mid]) {
			return binarysearch(start, mid - 1, number);
		} else if (number > a[mid]) {
			return binarysearch(mid + 1, end, number);
		} else {
			if (binarysearch(start, mid - 1, number) == -1) {
				return mid;
			} else {
				return binarysearch(start, mid - 1, number);
			}
		}
	} else {
		return -1;
	}
}

double length(double num)
{
    return num >= 0 ? num : -num;
}

double find_sqrt(double left, double right, double y)
{
    double x = (left + right) / 2;
    if (length(x * x - y) < 0.0001) {
        return x;
    } else if (x * x < y) {
        return find_sqrt(x, right, y);
    } else {
        return find_sqrt(left, x, y);
    }
}

double mysqrt(double y)
{
    return find_sqrt(0, y, y);
}

double power_calculation(double base, double x, int current_power, int total_power)
{
    int num = x;
    if (current_power == total_power) {
        return num;
    } else {
        if (current_power * 2 <= total_power) {
            count++;
            num *= x;
            return power_calculation(base, num, current_power * 2, total_power);
        } else {
            num = x * power_calculation(base, base, 1, total_power - current_power);
            return num;
        }
    }
}

double mypow_recursion(double x, int n)
{
    if (n == 1) {
        return x;
    } else if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        int half = mypow_recursion(x, n / 2);
        count++;
        return half * half;
    } else {
        count++;
        return mypow_recursion(x, n - 1) * x;
    }
}

double mypow_iteration(double x, int n)
{
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        n = n << 2;  /*每次移位，底数都要翻倍*/
        x *= x;
    }
    return result;
}

int main(void)
{
	int num = 10;
	// printf("%d\n", binarysearch(0, LEN - 1, num));
    // printf("%lf\n", mysqrt(458.0));
    printf("%lf\n", mypow_iteration(2, 10));
    printf("%lf\n", mypow_recursion(2, 10));
    printf("%d\n", count);

	return 0;
}
