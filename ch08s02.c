#include <stdio.h>
#include <time.h>
#define N 3

int a[N] = {1, 2, 3};

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

void print_array(int* a)
{
	for (int i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void print_full_permutation(int depth)
{
	if ( depth == N - 1 ) {
		// Base Case
		print_array(a);
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

int main(void)
{
	print_full_permutation(0);

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
