#include <stdio.h>
#include <stdarg.h>

#define length(num) ((num) < (0) ? (-num) : (num))
#define unit(num) num % 10

void int_to_string(int num)
{
    char number[10] = {0};
    if (num < 0) {
        putchar('-');
    }
    for (int i = 9; i >= 0; i--) {
        if (num == 0) {
            break;
        }
        number[i] = unit(length(num)) + 48;
        num /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (number[i] == 0) {
            continue;
        }
        putchar(number[i]);
    }
}

void double_to_string(const double num)
{
	int integer_part = num;
	int fractional_part = (num - (int)num) * 1000000;
    int_to_string(integer_part);
    putchar('.');
    int_to_string(fractional_part);
}

void my_printf(const char *format, ...)
{
    va_list ap;
    char c;

    va_start(ap, format);
    while (c = *format++) {
        if (c == '%') {
            switch (*format) {
            case 'd':
                int num = va_arg(ap, int);
                int_to_string(num);
                format++;
                break;
            case 'f':
                double float_num = va_arg(ap, double);
                double_to_string(float_num);
                format++;
                break;
            case 'c':
                /* char is promoted to int when passed through '...' */
                char ch = va_arg(ap, int);
                putchar(ch);
                format++;
                break;
            case 's':
                char *p = va_arg(ap, char *);
                fputs(p, stdout);
                format++;
                break;
            default :
                putchar(c);
                break;
            }
            continue;
        }
        putchar(c);
    }
    va_end(ap);
}

int main(void)
{
    my_printf("This is a double: %f\n"
              "This is a integer: %d\n"
              "This is a char: %c\n"
              "This is the end.\n",
               1321311.322135, 5, 'G');
    return 0;
}
