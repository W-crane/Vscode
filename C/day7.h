#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mysort(int (*func1)(const char *, const char *), void (*func2)(char a[][20], int, int), char names[][20], int len)
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (func1(names[j], names[j + 1]) > 0)
                func2(names, j, j + 1);
        }
    }
}

void swap(char a[10][20], int i, int j)
{
    char temp_str[20] = {0};
    strcpy(temp_str, a[i]);
    strcpy(a[i], a[j]);
    strcpy(a[j], temp_str);
}

void func7_11_7()
{
    // ϰ��11.7
    char names[10][20] = {
        "b",
        "a",
        "d",
        "c"};
    mysort(strcmp, swap, names, 4);
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", names[i]);
    }
}

int binary_search(int a[], int len, int num)
{
    // ʹ��ָ����ж��ֲ���
    int *left = a, *right = a + len - 1, *mid = a + (right - left) / 2;
    while (left <= right)
    {
        if (*mid == num)
            return mid - a;
        if (*mid > num)
            right = mid - 1;
        if (*mid < num)
            left = mid + 1;
        mid = a + (right - a + left - a) / 2;
    }
    return -1;
}

void func7_11_8()
{
    // ϰ��11.8
    int a[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    printf("%d\n", binary_search(a, 9, 1));
}

void func7_1()
{
    // �����ļ��Ķ�������ʹ��fgetc��ȡ
    FILE *fp = fopen("./file1.txt", "r");
    char c = '1';
    if (fp == NULL)
    {
        perror("�ļ���ʧ��"); // ����������Ϣ������һ���ַ���������ƴ����ʵ�ʴ�����Ϣǰ
        return;
    }
    // 1��ʹ��feof�ж��Ƿ񵽽�β���Ƽ���
    // while (!feof(fp))
    // {
    //     c = fgetc(fp);
    //     printf("%c", c);
    // }
    // 2�� ʹ��EOF�ж��Ƿ񵽽�β
    while (c != EOF)
    {
        c = fgetc(fp);
        printf("%c", c);
    }
    fclose(fp);
}

void func7_2()
{
    // �����ļ��Ķ�������ʹ��fgets��ȡ
    FILE *fp = fopen("./file1.txt", "r");
    char buf[30] = {0};
    if (fp == NULL)
    {
        perror("�ļ���ʧ��"); // ����������Ϣ������һ���ַ���������ƴ����ʵ�ʴ�����Ϣǰ
        return;
    }
    while (!feof(fp))
    {
        fgets(buf, sizeof(buf), fp);
        printf("%s", buf);
    }
    fclose(fp);
}

void func7_3()
{
    // �����ļ��Ķ�������ʹ��fscanf��ȡ
    FILE *fp = fopen("./file2.txt", "r");
    char buf[30] = {0};
    int num;
    char c;
    float f;
    if (fp == NULL)
    {
        perror("�ļ���ʧ��"); // ����������Ϣ������һ���ַ���������ƴ����ʵ�ʴ�����Ϣǰ
        return;
    }
    while (!feof(fp))
    {
        fscanf(fp, "%d %s %f %c", &num, buf, &f, &c);
        printf("%d\t%s\t%f\t%c\n", num, buf, f, c);
    }
    fclose(fp);
}

void func7_4()
{
    // �����ļ���д������ʹ��fputcд��
    FILE *fp = fopen("./write_files/file3.txt", "w");
    if (fp == NULL)
    {
        perror("�ļ���ʧ��"); // ����������Ϣ������һ���ַ���������ƴ����ʵ�ʴ�����Ϣǰ
        return;
    }
    int i = fputc('a', fp);
    printf("%c", i);
    fclose(fp);
}

void func7_5()
{
    // �����ļ���д������ʹ��fputsд�룬д�����ж�ȡ
    FILE *fp = fopen("./write_files/file4.txt", "r+");
    char buf[50] = {0};
    if (fp == NULL)
    {
        perror("�ļ���ʧ��"); // ����������Ϣ������һ���ַ���������ƴ����ʵ�ʴ�����Ϣǰ
        return;
    }
    int res = fputs("������fputsд����ļ�\n", fp);
    printf("return:%d\n", res);
    rewind(fp);
    while (!feof(fp))
    {
        fscanf(fp, "%s", buf);
        printf("%s", buf);
    }
    fclose(fp);
}

void func7_6()
{
    // �����ļ���д������ʹ��fprintfд��
    FILE *fp = fopen("./write_files/file5.txt", "w");
    char buf[50] = {0};
    if (fp == NULL)
    {
        perror("�ļ���ʧ��"); // ����������Ϣ������һ���ַ���������ƴ����ʵ�ʴ�����Ϣǰ
        return;
    }
    int res = fprintf(fp, "%d��������fprintfд����ļ�\n", 1);
    printf("return:%d\n", res);

    fclose(fp);
}

void func7_7()
{
    // ʹ��fseek���������ļ�ָ��λ��

    FILE *fp = fopen("./file4.txt", "r");
    if (fp == NULL)
    {
        perror("�ļ���ʧ��"); // ����������Ϣ������һ���ַ���������ƴ����ʵ�ʴ�����Ϣǰ
        return;
    }
    fseek(fp, 2, SEEK_SET);
    putchar(fgetc(fp));
    fseek(fp, 2, SEEK_CUR);
    putchar(fgetc(fp));
    fseek(fp, 0, SEEK_END);
    putchar(fgetc(fp));
    fclose(fp);
}

int copy_file(char *file, char *new_file)
{
    FILE *fp_r = fopen(file, "r");
    FILE *fp_w = fopen(new_file, "w");
    char buf[100] = {0};
    if (fp_r == NULL || fp_w == NULL)
    {
        perror("�ļ���ʧ��"); // ����������Ϣ������һ���ַ���������ƴ����ʵ�ʴ�����Ϣǰ
        return -1;
    }
    while (!feof(fp_r))
    {
        fgets(buf, sizeof buf, fp_r);
        fputs(buf, fp_w);
    }
    fclose(fp_r);
    fclose(fp_w);
    return 0;
}

void test_cp_file()
{
    copy_file("./file1.txt", "./new_file1.txt");
}