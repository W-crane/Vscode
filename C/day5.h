#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    char str[10];
    int num;
} Struct1;

void func5_1()
{
    // 验证结构体内部定义数组时的复制
    Struct1 s1 = {"hello", 1};
    Struct1 s2 = s1;
    printf("%d\t%d\n", s1.str, s2.str);
}

typedef struct
{
    char *str;
    int num;
} Struct2;

void func5_2()
{
    // 验证结构体内部定义指针时的复制
    Struct2 s1;
    s1.str = (char *)malloc(sizeof(char) * 10);
    s1.num = 10;
    Struct2 s2 = s1;
    printf("%d\t%d\n", s1.str, s2.str);
}

typedef struct
{
    int i;
    float f;
    char c;
    short int si;
} Struct3;

void func5_3()
{
    // 结构体的内存对齐
    Struct3 s;
    printf("float:%d, char:%d, short int:%d, int:%d, total:%d\n", sizeof s.f, sizeof s.c, sizeof s.si, sizeof s.i, sizeof s);
    printf("float_add:%d, char_add:%d, short int_add:%d, int_add:%d\n", &s.f, &s.c, &s.si, &s.i);
}

void func5_4()
{
    Struct1 s_s[3] = {
        "hello",
        1,
        {
            "asad",
        },
        "zxcv",
        3};
    for (int i = 0; i < 3; i++)
    {
        printf("%s\t%d\n", s_s[i].str, s_s[i].num);
    }
}

void func5_5()
{
    // 验证定义数组的结构体的内存对齐
    printf("%d\n", sizeof(Struct1));
}

typedef struct
{
    int num;
    Struct2 s; // 使用已定义结构体作为自身字段
    struct In  // 使用内部定义的结构体作为自身字段
    {
        char c;
        float f;
    } in;

} Out;

void func5_6()
{
    Out o;
}

typedef union
{
    float f;
    int i;
    char c;
    short int si;
} Union1;

void func5_7()
{
    // 共用体数据的存取
    Union1 u;
    u.i = 1;
    printf("%d\n", u.i);
    u.c = 'a';
    printf("%d\n", u.i);
}

void func5_8()
{
    Union1 u;
    printf("char_addr:%d\tint_addr:%d\n", &u.c, &u.i);
    printf("char:%d\tint:%d\n", sizeof u.c, sizeof u.i);
}

typedef union
{
    float f;
    short int arr[2];
    short int si;
} Union2;

void func5_9()
{
    Union2 u;
    u.arr[1] = 128;
    u.si = 256;
    printf("%d\n", u.arr[1]);
    printf("%d\n", u.arr[0]);
}

typedef struct
{
    unsigned sex : 1;
    unsigned age : 7;
    unsigned num : 12;
} Area;

void func5_10()
{
    Area a;
    printf("%d\n", sizeof a);
}

typedef struct
{
    char name[10];
    int age;
    union
    {
        char Student_id[10];
        char teacher_id[12];
    } id;
} Person;

void func5_11()
{
    Struct3 s;
    scanf("%d", &s);
    printf("%d\n", s.i);
    printf("%d\n", s);
}

