#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delim_arrive(const char code, const char *delim)
{
    while (*delim != '\0') {
        if (code == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

char *my_strtok(char *str, const char *delim)
{
    static char *next_tok = NULL;
    if (str == NULL) {
        str = next_tok;
    }
    char ch = *str;
    int i = 0;
    while (!delim_arrive(ch, delim) && ch != '\0') {
        ch = str[++i];
    }
    if (ch == '\0') {
        return NULL;
    }
    while (delim_arrive(str[i + 1], delim)) {
        str[i++] = '\0';
    }
    str[i] = '\0';
    next_tok = &str[i + 1];
    return str;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (str == NULL) {
        str = *saveptr;
    }
    char ch = *str;
    int i = 0;
    while (!delim_arrive(ch, delim) && ch != '\0') {
        ch = str[++i];
    }
    if (ch == '\0') {
        return NULL;
    }
    while (delim_arrive(str[i + 1], delim)) {
        str[i++] = '\0';
    }
    str[i] = '\0';
    *saveptr = &str[i + 1];
    return str;
}

int main(int argc, char *argv[])
{
    /*-----------------第一部分代码-----------------------
	char str[] = "root:x::0:root:/root:/bin/bash:";
	char *token;

	token = my_strtok(str, ":");
	printf("%s\n", token);
	while ( (token = my_strtok(NULL, ":")) != NULL)
		printf("%s\n", token);

    char *str1, *str2, *token, *subtoken;
	char *saveptr1, *saveptr2;
	int j;

	if (argc != 4) {
		fprintf(stderr, "Usage: %s string delim subdelim\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}

	for (j = 1, str1 = argv[1]; ; j++, str1 = NULL) {
		token = strtok_r(str1, argv[2], &saveptr1);
		if (token == NULL)
			break;
		printf("%d: %s\n", j, token);

		for (str2 = token; ; str2 = NULL) {
			subtoken = strtok_r(str2, argv[3], &saveptr2);
			if (subtoken == NULL)
				break;
			printf(" --> %s\n", subtoken);
		}
	}

	exit(EXIT_SUCCESS);
    ---------------------------------------------------*/

	return 0;
}
