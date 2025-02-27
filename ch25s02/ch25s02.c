#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

unsigned int get_number(FILE *target, size_t len)
{
    if (fseek(target, -len, SEEK_END) == -1) {
        return 0;
    }

    unsigned int result = 0;
    int num[5] = {-1, -1, -1, -1, -1};
    int ch = fgetc(target);
    int i = 0;
    int digit = 1;
    while (ch != ' ') {
        num[i] = (ch - 48);
        i++;
        ch = fgetc(target);
    }
    for (int i = 4; i >= 0; i--) {
        if (num[i] == -1)
            continue;
        result += num[i] * digit;
        digit *= 10;
    }

    return result;
}

void mycp(char *src, char *dst)
{
    FILE *src_fp = fopen(src, "r");
    FILE *dst_fp = fopen(dst, "w");
    char err_msg[6] = "Open ";
    if (src_fp == NULL) {
        perror(strcat(err_msg, src));
        exit(1);
    }
    if (dst_fp == NULL) {
        perror(strcat(err_msg, dst));
        exit(1);
    }

    int ch;
    while ( (ch = fgetc(src_fp)) != EOF ) {
        fputc(ch, dst_fp);
    }

    fclose(dst_fp);
    fclose(src_fp);
}

void cp_f(char *src, char *dst)
{
    FILE *src_fp = fopen(src, "r");
    FILE *dst_fp = fopen(dst, "w");
    char err_msg[6] = "Open ";
    if (src_fp == NULL) {
        perror(strcat(err_msg, src));
        exit(1);
    }
    if (dst_fp == NULL) {
        perror(strcat(err_msg, dst));
        exit(1);
    }
    char buf[10];
    while (fgets(buf, 10, src_fp) != NULL) {
        fputs(buf, dst_fp);
    }

    fclose(dst_fp);
    fclose(src_fp);
}

int main(int args, char *argv[])
{
    /*----------第一部分习题*--------------
    FILE *(fp[10]);

    fp[0] = fopen("/etc/shadow", "r");
    if (fp[0] == NULL) {
        perror("Open /etc/shadow");
    } else {
        fclose(fp[0]);
    }

    fp[1] = fopen("~/dsada", "r");
    if (fp[1] == NULL) {
        perror("Open ~/dsada");
    } else {
        fclose(fp[1]);
    }

    fp[2] = fopen("/home/akaedu/", "r+");
    if (fp[2] == NULL) {
        perror("Open /home/akaedu");
    } else {
        fclose(fp[2]);
    }

    fp[3] = fopen("/home/akaedu/", "r+");
    if (fp[2] == NULL) {
        perror("Open /home/akaedu");
    } else {
        fclose(fp[2]);
    }
    ------------------------------------*/

    /*----------第二部分习题*--------------
    mycp(argv[1], argv[2]);
    
    FILE *fp;
	int ch, i = 0;
    
	if ( (fp = fopen("file2", "w+")) == NULL) {
		perror("Open file file2\n");
		exit(1);
	}
	while ( (ch = getchar()) != EOF) {
        printf("%d ", i++);
		fputc(ch, fp);
    }
	rewind(fp);
	while ( (ch = fgetc(fp)) != EOF)
    putchar(ch);
	fclose(fp);
    ------------------------------------*/

    /*----------第三部分习题*--------------
    cp_f(argv[1], argv[2]);
    ------------------------------------*/

    /*----------第四部分习题*--------------*/
    FILE *fp = fopen("./text.txt", "a+");
    size_t buf_size = 26;
    char buf[buf_size];
    time_t current_time;

    int i = get_number(fp, buf_size);
    while (1) {
        /*|1     2025-02-26 15:36:00\0| 25*/
        i++;
        time(&current_time);
        strftime(buf, buf_size, "%Y-%m-%d %X", localtime(&current_time));
        fprintf(fp, "%-5d %s\n", i, buf);
        fflush(fp);
        sleep(1);
    }

    fclose(fp);
    /*-----------------------------------*/

    return 0;
}
