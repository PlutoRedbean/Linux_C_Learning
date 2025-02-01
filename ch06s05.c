#include <stdio.h>

void multiplication_table();

void diamond(int, char);

void multiplication_table()
{
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d\t", i * j);
        }
        printf("\n");
    }
}

void diamond(int num, char code)
{
    if (num % 2 == 0) {
        printf("ERROR!\n");
        return;
    }
    int k = 1;
    for (int i = 1; i <= num; i++) {
        if (i == (num + 1) / 2) {
            for (int j = 1; j <= num; j++) {
                printf("%c\t", code);
            }
        } else if (i < (num + 1) / 2) {
            for (int j = 1; j <= (num + 1) / 2 + i - 1; j++) {
                if (j <= ((num + 1) / 2 + i - 1) - (2 * i - 1)) {
                    printf("\t");
                }
                else {
                    printf("%c\t", code);
                }
            }
        } else {
            for (int j = 1; j <= num - k; j++) {
                if (j <= num - k - (num - k * 2)) {
                    printf("\t");
                }
                else {
                    printf("%c\t", code);
                }
            }
            k++;
        }
        printf("\n");
    }
}

int main(void)
{
    multiplication_table();
    printf("\n");
    diamond(7, '+');
    
	return 0;
}
