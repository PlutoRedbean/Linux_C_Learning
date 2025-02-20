#include <stdio.h>

int countbit(unsigned int x)
{
    int result = 0;
    while (x > 0) {
        if (x & 1U) {
            result++;
        }
        x >>= 1;
    }
    return result;
}

unsigned int multiply(unsigned int x, unsigned int y)
{
    if (x == 0 || y == 0) {
        return 0;
    }
    
    int result = 0;
    int power = 0;
    while (y > 0) {
        if (y & 1U) {
            result += x << power;
        }
        y >>= 1;
        power++;
    }
    return result;
}

unsigned int rotate_right(unsigned int x, unsigned int num)
{
    for (int i = 1; i <= num; i++) {
        unsigned int temp = x & 1U;
        x >>= 1;
        x += temp << 31;
    }
    return x;
}

// void swap(unsigned int* a, unsigned int* b)
// {
//     *a = ;
// }

int main()
{
    // int i = 0xcffffff3;
	// printf("%x\n", 0xcffffff3>>2);	// 1100->0011
	// printf("%x\n", i>>2);	        // 有符号数1100->1111

    // printf("%d\n", countbit(0b111011101111));
    // printf("%d\n", multiply(27, 50));
    // printf("%x\n", rotate_right(0xdeadbeff, 16));

    // swap
    unsigned int a = 5, b = 10;
    b &= 0x0000ffff;
    a <<= 16;
    b = a + b;
    a = a + b;
    b >>= 16;
    a &= 0x0000ffff;
    printf("%d, %d\n", a, b);
    
    return 0;
}
