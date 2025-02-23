#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 4

int a[N] = {1, 2, 3, 4, 5};
int result[M];

void gen_random(int upper_bound)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < N; i++)
		a[i] = rand() % upper_bound;
}

int howmany(int value)
{
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] == value)
			++count;
	return count;
}

int factorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void array_assignment(int* a, int* b)
{
	for (int i = 0; i < N; i++) {
		a[i] = b[i];
	}
}

void print_array(int* a, int num)
{
	for (int i = 0; i < num; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*------------------------------------------------*/

void print_full_permutation(int depth)
{
	if ( depth == N - 1 ) {
		// Base Case
		print_array(a, N);
		return;
	} else {
		// Recursion
		for (int i = depth; i < N; i++) {
			swap(&a[depth], &a[i]);
			print_full_permutation(depth + 1);
			swap(&a[depth], &a[i]);
		}
	}
}

/*------------------------------------------------*/

// 挑1，再挑n-1个，挑到depth = M - 1时为Base Case
void combination(int start, int order)
{
	if (start == M - 1) {
		// Base Case
		for (int i = order; i < N; i++) {
			result[start] = a[i];
			print_array(result, M);
		}
		return;
	} else {
		// Recursion
		for (int i = order; i < N; i++) {
			result[start] = a[i];
			combination(start + 1, i + 1);
		}
	}
}

/*------------------------------------------------*/

// 先挑出M个，再对这M个全排列
void full_permutation(int depth)
{
	if ( depth == M - 1 ) {
		// Base Case
		print_array(result, M);
		return;
	} else {
		// Recursion
		for (int i = depth; i < M; i++) {
			swap(&result[depth], &result[i]);
			full_permutation(depth + 1);
			swap(&result[depth], &result[i]);
		}
	}
}

void permutation(int start, int order)
{
	if (start == M - 1) {
		// Base Case
		for (int i = order; i < N; i++) {
			result[start] = a[i];
			full_permutation(0);
		}
		return;
	} else {
		// Recursion
		for (int i = order; i < N; i++) {
			result[start] = a[i];
			permutation(start + 1, i + 1);
		}
	}
}

/*------------------------------------------------*/

int main(void)
{
	// print_full_permutation(0);
	// combination(0, 0);
	permutation(0, 0);

	/*int i, histogram[10] = {0};

	gen_random(10);
	for (i = 0; i < N; i++)
		histogram[a[i]]++;

	for (int i = 0; i < 10; i++) {
		printf("%d times : %d\n", i, histogram[i]);
	}

    int count = 0;
    for (int i = 0; i < N; i++) {
		if (i == 0) {
			printf("0 1 2 3 4 5 6 7 8 9\n");
			continue;
		}
        for (int j = 0; j < 19; j++) {
			if (j % 2 == 0 && histogram[j / 2] > 0) {
				histogram[j / 2]--;
				count++;
				printf("*");
			}
			else printf(" ");
        }
		printf("\n");
		if (count >= N)
			break;
    }*/
	return 0;
}
