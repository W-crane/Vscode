#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func4_8_4()
{
    // scanf读入单词
    char str[50], word[10], *p;
    int loc = 0, len, count = 0;
    printf("请输入一行文本：");
    gets(str);
    printf("请输入需要匹配的单词：");
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
    printf("出现了%d次\n", count);
    printf("char:%d\n", sizeof(str));
}

void func4_1()
{
    char str[12] = "hello world", substr[6] = "hello";
    char *substr_P = strstr(str, substr); // 返回子串所匹配到的地址
    printf("原字符串中的地址：%d， 字符串:%s\n", substr_P, substr_P);
    printf("子串的地址：%d， 字符串:%s", substr, substr);
}

// func4_2()
// {
//     // 验证无返回类型默认为什么
//     return 0;
// }

int *func4_3()
{
    // 通过返回数组返回多个值;
    int arr[] = {1, 2};
    int *arr_p = arr;
    return arr_p;
}

void test4_3()
{
    int *arr = func4_3();
    printf("返回的地址：%d", arr);
}

void hanoi(int n, char a, char b, char c)
{
    // 把n个盘子从a位置通过b位置移到c位置
    if (n == 0)
        return;
    hanoi(n - 1, a, c, b); // 把n-1个从a位置通过c位置移到b位置
    printf("把%c移到%c\n", a, c);
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
    // func4_4(matrix); // 必须匹配，会报错
}