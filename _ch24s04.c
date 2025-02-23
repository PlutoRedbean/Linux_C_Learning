#include <stdio.h>

static const char *msg[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
	"Thursday", "Friday", "Saturday"};

char *get_a_day(int idx)
{
	static char buf[20];
	// char buf[20]; ---> (null) (null)
	strcpy(buf, msg[idx]);
	return msg[idx];
}

int main(void)
{
    printf("%s %s\n", get_a_day(0), get_a_day(1));

	printf("%s\n", get_a_day(0));
	printf("%s\n", get_a_day(1));
    
    char *str0 = get_a_day(0);
    char *str1 = get_a_day(1);
    printf("%s\n", str0);
	printf("%s\n", str1);
	return 0;

    // 好问题：static未释放，作用域?
}
