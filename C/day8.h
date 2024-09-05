#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A 20
// #undef A
#ifdef A
void func8_5()
{
    printf("hello func8_5");
}
#endif

void func8_1()
{
    // 使用追加 a 模式，并使用ftell函数
    FILE *fp = fopen("./file1.txt", "a");
    if (fp == NULL)
    {
        perror("无法打开文件");
        return;
    }
    long int loc = ftell(fp);
    printf("%ld\t", loc); // 输出0，指针指向文件开头
    fseek(fp, 10, 0);
    loc = ftell(fp);
    printf("%ld\t", loc);
    fputc('1', fp);
    loc = ftell(fp);
    printf("%ld\n", loc);
    fclose(fp);
}

void func8_2()
{
    // 使用追加 a+ 模式，并使用ftell函数，出现了无法写入的问题
    FILE *fp = fopen("./file1.txt", "a+");
    if (fp == NULL)
    {
        perror("无法打开文件");
        return;
    }
    long int loc = ftell(fp);
    printf("%ld\t", loc); // 输出0，指针指向文件开头
    fseek(fp, 10, 0);
    // char c = fgetc(fp);
    // putchar(c); // 不会输出 指针移动到最后了
    putchar('\n');
    loc = ftell(fp);
    printf("%ld\t", loc);
    putc('1', fp);
    loc = ftell(fp);
    printf("%ld\n", loc);
    fclose(fp);
}

void func8_3()
{
    // 使用追加 r+ 模式，尝试对文件进行局部改写
    FILE *fp = fopen("./file1.txt", "r+"); // 成功，插入而非覆盖
    char str[20] = "213213";
    if (fp == NULL)
    {
        perror("无法打开文件");
        return;
    }
    // fseek(fp, 10, 0);
    // char c = fgetc(fp);
    // putchar(c); // 不会输出 指针移动到最后了
    // fgets(str, 20, fp);
    fseek(fp, 3, 0);
    fputc('\b', fp);
    fputc('3', fp);
    fclose(fp);
}

void func8_4()
{
    // printf("%d", a);
}