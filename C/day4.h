#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func4_8_4()
{
    // scanf���뵥��
    char str[50], word[10], *p;
    int loc = 0, len, count = 0;
    printf("������һ���ı���");
    gets(str);
    printf("��������Ҫƥ��ĵ��ʣ�");
    scanf("%s", word);
    len = strlen(word);
    while (1)
    {
        p = strstr(str + loc, word);
        if (p == NULL)
            break;
        loc = (p - str) / sizeof(char) + len;
        count++;
    }
    printf("������%d��\n", count);
    printf("char:%d\n", sizeof(str));
}

void func4_1()
{
    char str[12] = "hello world", substr[6] = "hello";
    char *substr_P = strstr(str, substr); // �����Ӵ���ƥ�䵽�ĵ�ַ
    printf("ԭ�ַ����еĵ�ַ��%d�� �ַ���:%s\n", substr_P, substr_P);
    printf("�Ӵ��ĵ�ַ��%d�� �ַ���:%s", substr, substr);
}

// func4_2()
// {
//     // ��֤�޷�������Ĭ��Ϊʲô
//     return 0;
// }

int *func4_3()
{
    // ͨ���������鷵�ض��ֵ;
    int arr[] = {1, 2};
    int *arr_p = arr;
    return arr_p;
}

void test4_3()
{
    int *arr = func4_3();
    printf("���صĵ�ַ��%d", arr);
}

void hanoi(int n, char a, char b, char c)
{
    // ��n�����Ӵ�aλ��ͨ��bλ���Ƶ�cλ��
    if (n == 0)
        return;
    hanoi(n - 1, a, c, b); // ��n-1����aλ��ͨ��cλ���Ƶ�bλ��
    printf("��%c�Ƶ�%c\n", a, c);
    hanoi(n - 1, c, a, b);
}

void test_hanoi()
{
    hanoi(3, 'a', 'b', 'c');
}

void func4_4(int matrix[][4])
{
}

void test_4_4()
{
    int matrix[][6] = {0};
    // func4_4(matrix); // ����ƥ�䣬�ᱨ��
}