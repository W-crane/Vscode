#include <stdio.h>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
#include "day8.h"

int main(int arg, char *arg1[])
{
    func8_5();

    // 使用命令行参数对指定文件的前n个字符进行倒叙改写
    //     if (arg != 3)
    //         return -1;
    //     int n = atoi(arg1[2]), i = 0, loc = 0;
    //     char text[200];
    //     FILE *fp_r = fopen(arg1[1], "r");

    //     while (!feof(fp_r))
    //         text[loc++] = getc(fp_r);
    //     printf("%s", text);
    //     fclose(fp_r);
    //     FILE *fp_w = fopen(arg1[1], "w");
    //     for (i = 0; i < n; i++)
    //         putc(text[n - i - 1], fp_w);
    //     for (i = n; i < strlen(text); i++)
    //         putc(text[i], fp_w);

    //     fclose(fp_w);
}