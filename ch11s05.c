#include <stdio.h>

#define N 10

int a[N] = {9, 1, 3, 4, 4, 4, 2, 2, 3, 4};

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

int order_statistic(int start, int end, int k)
{
	// 用partition函数把序列分成两半，中间的pivot元素是序列中的第i个;
	// if (k == i)
	// 	返回找到的元素;
	// else if (k > i)
	// 	从后半部分找出第k-i小的元素并返回;
	// else
	// 	从前半部分找出第k小的元素并返回;
    if (start == end) {
        return a[start];
    }
    int mid = partition(start, end);    // mid是数组的绝对下标
    int i = mid - start + 1;  // i是序列的pivot元素的相对第i个
    if (k == i) {
        return a[mid];
    } else if (k > i) {
        return order_statistic(mid + 1, end, k - i);
    } else {
        return order_statistic(start, mid - 1, k);
    }
}

int search_second_smallest(int start, int end)
{
    int smallest, result;
    if (a[start] < a[start + 1]) {
        smallest = a[start];
        result = a[start + 1];
    } else {
        smallest = a[start + 1];
        result = a[start];
    }
    for (int i = start + 1; i < end; i++) {
        if (a[i] < smallest) {
            smallest = a[i];
        }
        if (a[i] > smallest && a[i] < result) {
            result = a[i];
        }
    }
    return result;
}

int search_smallest(int start, int end)
{
    int result = a[0];
    for (int i = 0; i < N; i++) {
        result = result < a[i] ? result : a[i];
    }
    return result;
}

int main()
{
	printf("%d\n", order_statistic(0, N - 1, 4));

    return 0 ;
}
