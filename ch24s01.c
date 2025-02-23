#include <stdlib.h>
#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return src;
}

int my_strlen(char *src)
{
    int result = 0;
    for (int i = 0; src[i] != '\0'; i++)
        result++;
    
    return result;
}

char *shrink_space(char *dest, const char *src, size_t n)
{
    int src_length = my_strlen(src);
    int dest_num = 0;
    for (int i = 0; i < src_length; i++) {
        if (dest[dest_num - 1] == ' ' && (src[i] == ' ' || src[i] == '\t' || src[i] == '\n')) {
            continue;
        }
        if (src[i] == '\t' || src[i] == '\n') {
            dest[dest_num] = ' ';
            dest_num++;
            continue;
        }
        if (src[i - 1] == '\t' && src[i] == '\t') {
            continue;
        }
        dest[dest_num] = src[i];
        dest_num++;
    }

    for (int i = dest_num; i < n; i++) {
        if (i > my_strlen(dest)) {
            break;
        }
        dest[i] = '\0';
    }
    
    return src;
}

int main()
{
    char buf[] = "This Content hoho       is ok\nok?\n\t\tfile system\nuttered words   ok ok      ?\nend.";
    char dest[100];
    // printf("%s\n", my_strcpy(buf, "hello"));
    // printf("%s\n", buf);
    shrink_space(dest, buf, 100);
    printf("%s\n", dest);

    // for (int i = 0; true; i++) {
	// 	malloc(1024 * 1024 * 1024);
	// }
	// 程序被强制杀死，触发内存不足（OOM）杀手机制

    return 0;
}
