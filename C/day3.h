#include <stdio.h>
#include <math.h>
#include <string.h>

void func3_1()
{
    // 判断for内的循环条件是否可以是多个表达式
    int i, j;
    for (i = 0, j = 10; i < 5, j > 7; i++, j--)
    {
        printf("i = %d\tj = %d\n", i, j);
    }
}

void func3_2()
{
    // 画sinx图像
    int x = 0, y;
    for (x = 0; x <= 180; x += 15)
    {
        y = (int)50 * sin(x / 180.0 * 3.14) + 0.5;
        for (int i = 0; i < y - 1; i++)
        {
            printf(" ");
        }
        printf("*\n");
    }
}

void func3_3()
{
    // 字符串初始化
    char str[10] = "hello"; // {'h' , 'e', 'l' ,... ,'\0'...}
    // char str[10] = "hello\\0";  // 打印  “hello\0”
    // for (int i = 6; i < 10; i++)
    // {
    //     printf("第%d位是否为\\0:%d\n", i, (str[i] == '\0'));
    // }
    printf("%s\n", str);
}

char ext_arr[5];

void fun3_4()
{
    // 定义static以及extern数组查看默认初始化值
    static char sta_arr[5];
    printf("\\0的值为：%d\n", '\0');
    for (int i = 0; i < 5; i++)
    {
        printf("ext:%d\tsta:%d\n", ext_arr[i], sta_arr[i]);
    }
}

void func3_5()
{
    // 二维数组存储结构
    int m[3][4] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", &m[i][j]);
        }
    }
}

void func3_6()
{
    // scanf输入字符串
    char str[10];
    gets(str);
    printf("%s\n", str);
}

void func3_7()
{
    // 访问数组超出范围是什么错误
    int a[5] = {0};
    int i = a[6]; // 读不报错
    printf("%d\t%d\n", i, a + 6);
    // a[6] += 1; // 写报错
}

void func3_8()
{
    // 字符数组的初始化以及赋值
    char s1[4] = "abc";
    // char s2[4] = s1; // 地址之间的赋值，但是报错了
    char *s2 = s1; // 地址之间的赋值，没抱错
}

void func3_9()
{
    // strcpy使用
    char a[10] = "hello";
    // printf("cpy:%s\n", strcpy(a, "ab"));      // 会自动在后面加上\0 所以本质上是覆盖
    printf("ncpy:%s\n", strncpy(a, "ab", 1)); // 不会自动在后面加上 不是覆盖
}