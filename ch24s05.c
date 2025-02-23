#include <stdio.h>

#define LEN 5

typedef void (*sort)(int, void *);

typedef int (*cmp)(const void *, const int, const double);

void double_sort(int j, void *arr)
{
    double *array = (double *)arr;
	double key = array[j];
	int i = j - 1;
	while (i >= 0 && array[i] > key) {
		array[i+1] = array[i];
		i--;
	}
	array[i+1] = key;
}

void int_sort(int j, void *arr)
{
    int *array = (int *)arr;
	int key = array[j];
	int i = j - 1;
	while (i >= 0 && array[i] > key) {
		array[i+1] = array[i];
		i--;
	}
	array[i+1] = key;
}

void insertion_sort(void *array, sort sort)
{
	int j;
	for (j = 1; j < LEN; j++) {
		sort(j, array);
	}
}

sort *sort_double = double_sort;
sort *sort_int = int_sort;

/*--------------------------------------------------*/

int double_cmp(const void * arr, const int subscript, const double b)
{
	double *array = (double *)arr;
    double diff = array[subscript] - b;
    return (diff > 0) - (diff < 0);
}

int int_cmp(const void * arr, const int subscript, const double b)
{
	int *array = (int *)arr;
    return (array[subscript] > (int)b) - (array[subscript] < (int)b);
}

int binarysearch(double number, void *array, cmp cmp)
{
	int mid, start = 0, end = LEN - 1;

	// printf("%d\n", (int)number);
	while (start <= end) {
		mid = (start + end) / 2;
		if (cmp(array, mid, number) == -1)
			start = mid + 1;
		else if (cmp(array, mid, number) == 1)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

cmp *cmp_double = double_cmp;
cmp *cmp_int = int_cmp;

/*--------------------------------------------------*/

int main(void)
{
    int a[LEN] = { 1, 2, 2, 5, 7 };
    double b[LEN] = { 4.2, 5.0, 7.4, 7.6, 8.0 };
	// insertion_sort((void *)b, sort_double);
	// for (size_t i = 0; i < LEN; i++) {
    //     printf("%f ", b[i]);
    // }
    // printf("\n");

	printf("%d\n", binarysearch(8, (void *)b, double_cmp));

	return 0;
}
