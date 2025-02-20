#include <stdio.h>

int main()
{
    int i = 0;
    unsigned int sum = 0;
    for (; i < 16; i++)
        sum = sum + 1U << i;    // 没并非左移16位，不为0xffff
    return 0;
}
