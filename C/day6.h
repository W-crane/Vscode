#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void func6_1()
{
    // ȡ����ĵ�ַ
    int arr[3] = {0};
    int(*p)[3] = &arr;

    // ����ʹ��֮ǰδ��ʼ����
    int *p1 = NULL;
    printf("---------------\n");
    printf("%d\n", *p1); // vc++����
    printf("---------------\n");
    p1[0] = 1;
    printf("---------------\n"); // vc++����
}

void func6_2()
{
    // ָ��������
    int x = 0, y = 1, *px = &x, *py = &y;
    // int *p = px + py;   // �޷�������
}

void func6_3()
{
    // ָ����������Լ�
    int x = 0;
    int *p = &x;
    printf("%u\t%u\t%u\n", p++, p, p + 1);
}

void func6_4()
{
    // ��ά�����ָ��
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
    // ָ�����������ָ��

    // ָ�����飬�洢������charָ��
    char str1[10] = "ads", str2[10] = "asdf", c = 'a';
    char *p[3] = {str1, str2, &c};
    printf("ָ�����飺%u\t%u\t%u\n", p[0], p[1], p[2]);

    char p2[3][5] = {"asd", "cxzv", "eqwr"};
    printf("��ά���飺%u\t%u\t%u\n", p2[0], p2[1], p2[2]);

    // ����ָ��
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
    // ����ָ��
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
    // �ṹ��ָ�룬���ַ���ȡֵ
    Struct7 s = {1, 1.0, 'a', 2}, *p = &s;
    printf("%d\n", s.i);
    printf("%d\n", (*p).i);
    printf("%d\n", p->i);
}