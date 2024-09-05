#include <stdio.h>
#include <math.h>
#include <string.h>

void func3_1()
{
    // �ж�for�ڵ�ѭ�������Ƿ�����Ƕ�����ʽ
    int i, j;
    for (i = 0, j = 10; i < 5, j > 7; i++, j--)
    {
        printf("i = %d\tj = %d\n", i, j);
    }
}

void func3_2()
{
    // ��sinxͼ��
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
    // �ַ�����ʼ��
    char str[10] = "hello"; // {'h' , 'e', 'l' ,... ,'\0'...}
    // char str[10] = "hello\\0";  // ��ӡ  ��hello\0��
    // for (int i = 6; i < 10; i++)
    // {
    //     printf("��%dλ�Ƿ�Ϊ\\0:%d\n", i, (str[i] == '\0'));
    // }
    printf("%s\n", str);
}

char ext_arr[5];

void fun3_4()
{
    // ����static�Լ�extern����鿴Ĭ�ϳ�ʼ��ֵ
    static char sta_arr[5];
    printf("\\0��ֵΪ��%d\n", '\0');
    for (int i = 0; i < 5; i++)
    {
        printf("ext:%d\tsta:%d\n", ext_arr[i], sta_arr[i]);
    }
}

void func3_5()
{
    // ��ά����洢�ṹ
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
    // scanf�����ַ���
    char str[10];
    gets(str);
    printf("%s\n", str);
}

void func3_7()
{
    // �������鳬����Χ��ʲô����
    int a[5] = {0};
    int i = a[6]; // ��������
    printf("%d\t%d\n", i, a + 6);
    // a[6] += 1; // д����
}

void func3_8()
{
    // �ַ�����ĳ�ʼ���Լ���ֵ
    char s1[4] = "abc";
    // char s2[4] = s1; // ��ַ֮��ĸ�ֵ�����Ǳ�����
    char *s2 = s1; // ��ַ֮��ĸ�ֵ��û����
}

void func3_9()
{
    // strcpyʹ��
    char a[10] = "hello";
    // printf("cpy:%s\n", strcpy(a, "ab"));      // ���Զ��ں������\0 ���Ա������Ǹ���
    printf("ncpy:%s\n", strncpy(a, "ab", 1)); // �����Զ��ں������ ���Ǹ���
}