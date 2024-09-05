#include <stdio.h>
#include <stdlib.h>

typedef struct SList
{
    int *element;
    int max_length;
    int length;
} SList;

void init_list(SList *s)
{
    s->element = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        s->element[i] = 0;
    }
    s->max_length = 10;
    s->length = 0;
}

void print_list(const char *str, SList s)
{
    printf("%s\n", str);
    printf("Elements:");
    for (int i = 0; i < s.length; i++)
    {
        printf("%d  ", s.element[i]);
    }
    printf("\n");
    printf("Length:%d\n", s.length);
    printf("Max Length:%d\n", s.max_length);
    printf("\n");
}

int add_back(SList *s, int num)
{
    if (s->length == s->max_length)
        return 0;
    s->element[s->length] = num;
    s->length++;
    return 1;
}

int add_head(SList *s, int num)
{
    if (s->length == s->max_length)
        return 0;
    for (int i = s->length - 1; i >= 0; i--)
    {
        s->element[i + 1] = s->element[i];
    }
    s->element[0] = num;
    s->length++;
}

int extend_length(SList *s, int new_length)
{
    if (new_length <= s->max_length)
        return 0;
    int *p;
    p = (int *)malloc(sizeof(int) * s->length);
    for (int i = 0; i < s->length; i++)
        p[i] = s->element[i];
    s->max_length = new_length;
    s->element = (int *)malloc(sizeof(int) * new_length);
    for (int i = 0; i < s->length; i++)
        s->element[i] = p[i];
    return 1;
}

int insert_num(SList *s, int num, int loc)
{
    if (s->length == s->max_length)
        return -1;

    if (loc > s->max_length)
        return 0;

    if (loc > s->length + 1)
    {
        s->element[s->length++] = num;
        return 1;
    }

    for (int i = s->length - 1; i > loc - 2; i--)
    {
        s->element[i + 1] = s->element[i];
    }
    s->element[loc - 1] = num;
    s->length++;
    return 1;
}

int pop_num(SList *s)
{
    if (s->length == 0)
        return 0;

    s->element[s->length - 1] = 0;
    s->length--;
    return s->length;
}

int pop_head(SList *s)
{
    if (s->length == 0)
        return 0;

    for (int i = 1; i < s->length; i++)
    {
        s->element[i - 1] = s->element[i];
    }
    pop_num(s);
    return s->length;
}

int search_loc(SList s, int loc)
{
    if (loc > s.length)
        return -1;
    return s.element[loc - 1];
}

int search_num(SList s, int num)
{
    for (int i = 0; i < s.length; i++)
    {
        if (s.element[i] == num)
            return i + 1;
    }
    return -1;
}

int del_by_loc(SList *s, int loc)
{
    if (loc > s->length || loc < 1)
        return -1;

    int num = search_loc(*s, loc);

    for (int i = loc; i < s->length; i++)
    {
        s->element[i - 1] = s->element[i];
    }
    pop_num(s);
    return num;
}

int del_by_num(SList *s, int num)
{
    int loc = search_num(*s, num);

    del_by_loc(s, loc);

    return loc;
}

int copy_element(SList s1, SList *s2)
{
    if (s1.length > s2->max_length)
        return -1;

    for (int i = 0; i < s1.length; i++)
    {
        s2->element[i] = s1.element[i];
    }

    s2->length = s1.length;
    return 1;
}

int change_by_loc(SList *s, int loc, int num)
{
    if (loc > s->length || loc < 1)
        return 0;
    s->element[loc - 1] = num;
    return num;
}

int change_by_num(SList *s, int num1, int num2)
{
    int loc = search_num(*s, num1);
    change_by_loc(s, loc, num2);
    return loc;
}

int main(int argc, char *argv[])
{
    SList s, s2;
    init_list(&s);
    init_list(&s2);
    print_list("��ʼ����", s);
    add_back(&s, 1);
    add_back(&s, 2);
    add_back(&s, 3);
    add_head(&s, 7);
    add_head(&s, 6);
    add_head(&s, 10);
    extend_length(&s, 15);
    print_list("�Ӻ󷽲���1,2,3,��ǰ������7,6,10������,��������15��", s);
    insert_num(&s, 4, 4);
    insert_num(&s, 5, 2);
    insert_num(&s, 8, 9);
    print_list("����(4,4),(5,2),(8,9)������", s);
    pop_num(&s);
    print_list("�������Ԫ�غ�����", s);
    pop_head(&s);
    print_list("������ǰ��Ԫ�غ�����", s);
    del_by_loc(&s, 1);
    del_by_num(&s, 4);
    del_by_num(&s, 8);
    print_list("ɾ����һ��Ԫ���Լ���1��4��8Ԫ��֮������", s);
    copy_element(s, &s2);
    print_list("������1���ݸ��Ƶ�����2��", s2);
    change_by_loc(&s, 3, 5);
    print_list("������������Ϊ5", s);
    change_by_num(&s, 2, 8);
    return 0;
}
