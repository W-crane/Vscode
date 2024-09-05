#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void func6_1()
{
    // 取数组的地址
    int arr[3] = {0};
    int(*p)[3] = &arr;

    // 数组使用之前未初始化；
    int *p1 = NULL;
    printf("---------------\n");
    printf("%d\n", *p1); // vc++报错
    printf("---------------\n");
    p1[0] = 1;
    printf("---------------\n"); // vc++报错
}

void func6_2()
{
    // 指针变量相加
    int x = 0, y = 1, *px = &x, *py = &y;
    // int *p = px + py;   // 无法过编译
}

void func6_3()
{
    // 指针变量自增自减
    int x = 0;
    int *p = &x;
    printf("%u\t%u\t%u\n", p++, p, p + 1);
}

void func6_4()
{
    // 二维数组和指针
    int arr[3][3] = {0};
    int(*p)[3] = &(arr[0]);
}

void func6_5()
{
    char *str;
    printf("%u\n", str);
    str = "hello";
    printf("%u\n", str);
    str = (char *)malloc(sizeof(char) * 10);
    printf("%u\n", str);
}

void func6_6()
{
    // 指针数组和数组指针

    // 指针数组，存储着三个char指针
    char str1[10] = "ads", str2[10] = "asdf", c = 'a';
    char *p[3] = {str1, str2, &c};
    printf("指针数组：%u\t%u\t%u\n", p[0], p[1], p[2]);

    char p2[3][5] = {"asd", "cxzv", "eqwr"};
    printf("二维数组：%u\t%u\t%u\n", p2[0], p2[1], p2[2]);

    // 数组指针
    int arr[3] = {0};
    int(*p3)[] = &arr;
    printf("%u\n", p3);
}

float myadd(float x, float y)
{
    return x + y;
}

float myminus(float x, float y)
{
    return x - y;
}

float mymut(float x, float y)
{
    return x * y;
}

float mydiv(float x, float y)
{
    return x / y;
}

float myclc(float (*func)(float, float), float x, float y)
{
    return func(x, y);
}

void func6_7()
{
    // 函数指针
    float f1 = myclc(myadd, 1.0, 2.0);
    printf("%f", f1);
}

typedef struct
{
    int i;
    float f;
    char c;
    short int si;
} Struct7;

void func6_8()
{
    // 结构体指针，三种方法取值
    Struct7 s = {1, 1.0, 'a', 2}, *p = &s;
    printf("%d\n", s.i);
    printf("%d\n", (*p).i);
    printf("%d\n", p->i);
}