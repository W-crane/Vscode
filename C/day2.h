#include <stdio.h>
#include <math.h>

#define ACC 0.00001

void func2_1()
{
    // �жϻ������ǰ��Ϊ������߲���
    int a = 0, b = 1;

    a = 1;
    (a == 0) || b++;
    printf("%d\n", b);
}

void func2_2()
{
    // ��֤ �ж������������С�ڵ��ڣ� == ��ͣ�
    int a = 0, b = 1;
    int c = 0 == a <= b; // ����ִ�� == �� c = 1,����ִ�� <=����c����0
    printf("%d\n", c);
}

void func2_3()
{
    // ����ת��
    // ��ʽ����ת��
    double d = 1;
    // ��ʽ����ת�� (type)ֵ
    int i = (int)0.2;
}

void func2_4()
{
    // �ַ����ͱ���ʹ��
    char c; // �� c����ַ���д
    scanf("%c", &c);
    if (c >= 'a' && c <= 'z')
    {
        c = c + 'A' - 'a';
        printf("%c\n", c);
    }
    return;
}

void func2_5()
{
    // scanf������ʹ��
    // int i = 0, j = 0;
    // int res;
    // res = scanf("%d%d", &i, &j); // ����ֵ�ĺ��壺�ɹ�ƥ�䵽�˼�������
    // printf("%d\n", res);

    // ģ�⻺���������Ľ��
    // int i = 0;
    // char c;
    // scanf("%d", &i);
    // while (c = getchar(), c != EOF && c != '\n')
    //     ;
    // scanf("%d", &i);
    // scanf("%d", &i);
    // printf("%d\n", i);

    // scanf������һЩ���
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    printf("%d\t%d\t%d\n", i, j, k);
    scanf("%d,%d,%d", &i, &j, &k);
    printf("%d\t%d\t%d\n", i, j, k);
    scanf("%dand%dand%d", &i, &j, &k);
    printf("%d\t%d\t%d\n", i, j, k);
}

void func2_6()
{
    // ��ʽռλ��
    // %nd\s\c (nΪ����һ������)
    // printf("ռ���λ��,�Ҷ��룺%5d\n", 123);
    // printf("ռ���λ��,�Ҷ��룺%5s\n", "123");
    // printf("ռ���λ��,�Ҷ��룺%5c\n", '5');

    // �ж�%nc��%ns��scanf���Ƿ�ͬ
    // char str[10];
    // scanf("%5s", str);
    // printf("%s\n", str);
    // printf("%c\n", getchar());

    // %0nd ռn��λ�ã��Ҷ��룬���油��
    // int i = 10;
    // printf("%04d\n", i);

    // // %-nd/c/s��nΪ����һ�����֣� ռn��λ�ã������
    // int i = 10;
    // printf("%-4d��\n", i);

    // %m.nf һ������mλ������nλС��
    float d = 123.456;
    printf("%.2f\n", d);
    // printf("%-9.2f\n", d);
    // printf("%09.2f\n", d);
}




void func2_7()
{
    // ��ʽռλ���е� *
    int a = 12;
    printf("*", a);
}

void func2_8()
{
    // switch ʹ��
    int grade;
    scanf("%d", &grade);
    // 100��Ϊs�� 90-100 Ϊa�� 70-90 Ϊb�� 50-70Ϊc ��50һ��Ϊd
    switch (grade / 10)
    {
    case 10:
        printf("s");
        break;
    case 9:
        printf("a");
        break;
    case 8:
    case 7:
        printf("b");
        break;
    default:
        printf("c");
        break;
    }
}

void func2_5_3()
{
    double x, result = 0.0, i = 1.0, current = 1.0;
    scanf("%lf", &x);
    printf("%lf\n", x);
    while (1)
    {
        result += current;
        current *= (x / i++);
        if (current < ACC)
            break;
    }
    printf("%.5lf\n", result);
    printf("%.5lf\n", exp(x));
}
