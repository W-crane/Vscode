#include <stdio.h>
#include <math.h>

#define ACC 0.00001

void func2_1()
{
    // 判断或运算符前面为真后面走不走
    int a = 0, b = 1;

    a = 1;
    (a == 0) || b++;
    printf("%d\n", b);
}

void func2_2()
{
    // 验证 判断运算符（大于小于等于， == 最低）
    int a = 0, b = 1;
    int c = 0 == a <= b; // 若先执行 == 则 c = 1,若先执行 <=，则c等于0
    printf("%d\n", c);
}

void func2_3()
{
    // 类型转换
    // 隐式类型转换
    double d = 1;
    // 显式类型转换 (type)值
    int i = (int)0.2;
}

void func2_4()
{
    // 字符类型变量使用
    char c; // 把 c这个字符大写
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
    // scanf函数的使用
    // int i = 0, j = 0;
    // int res;
    // res = scanf("%d%d", &i, &j); // 返回值的含义：成功匹配到了几个变量
    // printf("%d\n", res);

    // 模拟缓冲区堵塞的解决
    // int i = 0;
    // char c;
    // scanf("%d", &i);
    // while (c = getchar(), c != EOF && c != '\n')
    //     ;
    // scanf("%d", &i);
    // scanf("%d", &i);
    // printf("%d\n", i);

    // scanf函数的一些情况
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
    // 格式占位符
    // %nd\s\c (n为任意一个数字)
    // printf("占五个位置,右对齐：%5d\n", 123);
    // printf("占五个位置,右对齐：%5s\n", "123");
    // printf("占五个位置,右对齐：%5c\n", '5');

    // 判断%nc与%ns在scanf里是否不同
    // char str[10];
    // scanf("%5s", str);
    // printf("%s\n", str);
    // printf("%c\n", getchar());

    // %0nd 占n个位置，右对齐，左面补零
    // int i = 10;
    // printf("%04d\n", i);

    // // %-nd/c/s（n为任意一个数字） 占n个位置，左对齐
    // int i = 10;
    // printf("%-4d啊\n", i);

    // %m.nf 一共保留m位，其中n位小数
    float d = 123.456;
    printf("%.2f\n", d);
    // printf("%-9.2f\n", d);
    // printf("%09.2f\n", d);
}




void func2_7()
{
    // 格式占位符中的 *
    int a = 12;
    printf("*", a);
}

void func2_8()
{
    // switch 使用
    int grade;
    scanf("%d", &grade);
    // 100分为s， 90-100 为a， 70-90 为b， 50-70为c ，50一下为d
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
