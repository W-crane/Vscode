#include <stdio.h>

void func1_1()
{
    static int a;
    // a++;
    printf("a = %d\n", a);
}

void func1_2_1()
{
    // ϰ��2.1
    int n;
    double result = 0.0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        result += 1 / (double)i;
    }
    printf("���Ϊ��%lf\n", result);
}
