#include <stdio.h>

#define N 10

int a[N] = {6, 6, 3, 3, 9, 8, 23, 23, 2, 4};

int partition(int start, int end)
{
    int pivot = a[start];
    int left[N] = {}, right[N] = {};
	// 从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
	// 在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
	// 使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素;
    int i = 0, j = 0, k = start + 1;
    while (k < end + 1) {
        if (a[k] < pivot) {
            left[i++] = a[k++];
        } else {
            right[j++] = a[k++];
        }
    }
    for (int x = 0; x < i; x++) {
        a[start + x] = left[x];
    }
    int mid = start + i;
    a[mid] = pivot;
    for (int x = 0; x < j; x++) {
        a[mid + x + 1] = right[x];
    }
	return mid;
}

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}

int main()
{
    quicksort(0, N - 1);
    for (int i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
