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
    // ʹ��׷�� a ģʽ����ʹ��ftell����
    FILE *fp = fopen("./file1.txt", "a");
    if (fp == NULL)
    {
        perror("�޷����ļ�");
        return;
    }
    long int loc = ftell(fp);
    printf("%ld\t", loc); // ���0��ָ��ָ���ļ���ͷ
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
    // ʹ��׷�� a+ ģʽ����ʹ��ftell�������������޷�д�������
    FILE *fp = fopen("./file1.txt", "a+");
    if (fp == NULL)
    {
        perror("�޷����ļ�");
        return;
    }
    long int loc = ftell(fp);
    printf("%ld\t", loc); // ���0��ָ��ָ���ļ���ͷ
    fseek(fp, 10, 0);
    // char c = fgetc(fp);
    // putchar(c); // ������� ָ���ƶ��������
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
    // ʹ��׷�� r+ ģʽ�����Զ��ļ����оֲ���д
    FILE *fp = fopen("./file1.txt", "r+"); // �ɹ���������Ǹ���
    char str[20] = "213213";
    if (fp == NULL)
    {
        perror("�޷����ļ�");
        return;
    }
    // fseek(fp, 10, 0);
    // char c = fgetc(fp);
    // putchar(c); // ������� ָ���ƶ��������
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