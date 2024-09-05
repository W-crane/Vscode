#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct Stack
{
    int *Elements;
    int length;
    int capacity;
} Stack;

void init_stack(Stack *s)
{
    s->capacity = 10;
    s->length = 0;
    s->Elements = (int *)malloc(10 * sizeof(int));
}

void print_list(Stack s)
{
    printf("Length:%d\n", s.length);
    printf("Capacity:%d\n", s.capacity);
    printf("Elements:");
    for (int i = 0; i < s.length; i++)
    {
        printf("%d  ", s.Elements[i]);
    }
    printf("\n");
    printf("\n");
}

int add_num(Stack *s, int num)
{
    if (s->length == s->capacity)
        return -1;
    s->Elements[s->length] = num;
    s->length++;
    return s->length;
}

int pop_num(Stack *s)
{
    if (s->length == 0)
        return -1;
    s->length--;
    return s->Elements[s->length];
}

int extend(Stack *s, int expand)
{
    int *temp;
    s->Elements = (int *)realloc(s->Elements, sizeof(int) * (expand + s->capacity));
    s->capacity += expand;
    return s->capacity;
}

int pop_compute(Stack *s1, Stack *s2)
{
    int operat, num_l, num_r;
    num_r = pop_num(s1);
    num_l = pop_num(s1);
    operat = pop_num(s2);
    switch (operat)
    {
    case 1:
        add_num(s1, num_l + num_r);
        break;
    case 2:
        add_num(s1, num_l - num_r);
        break;
    case 3:
        add_num(s1, num_l * num_r);
        break;
    case 4:
        add_num(s1, num_l / num_r);
        break;
    default:
        break;
    }
    return s1->Elements[s1->length - 1];
}

int main(int argc, char *argv[])
{
    Stack s1, s2;
    char v[50];
    int i = 0, front_is_num = 0;
    init_stack(&s1);
    init_stack(&s2);
    extend(&s1, 20);
    extend(&s2, 20);

    printf("please in put:");
    // scanf("%s", v);

    cin.getline(v, 50);

    while (v[i] != '\0')
    {
        if (v[i] >= '0' && v[i] <= '9')
        {
            if (front_is_num == 0)
            {
                add_num(&s1, v[i] - '0');
            }
            else
            {
                int num = pop_num(&s1) * 10 + v[i] - '0';
                add_num(&s1, num);
            }
            front_is_num = 1;
        }
        else if (v[i] == '+' || v[i] == '-' || v[i] == '*' || v[i] == '/' || v[i] == '(' || v[i] == ')')
        {
            front_is_num = 0;
            switch (v[i])
            {
            case '+':
            {
                while (1)
                {
                    if (s2.length == 0 || s2.Elements[s2.length - 1] == 5)
                        break;
                    pop_compute(&s1, &s2);
                }
                add_num(&s2, 1);
                break;
            }
            case '-':
            {
                while (1)
                {
                    if (s2.length == 0 || s2.Elements[s2.length - 1] == 5)
                        break;
                    pop_compute(&s1, &s2);
                }
                add_num(&s2, 2);
                break;
            }
            case '*':
            {
                while (1)
                {
                    if (s2.length == 0 || s2.Elements[s2.length - 1] == 5 || s2.Elements[s2.length - 1] < 3)
                        break;
                    pop_compute(&s1, &s2);
                }
                add_num(&s2, 3);
                break;
            }
            case '/':
            {
                while (1)
                {
                    if (s2.length == 0 || s2.Elements[s2.length - 1] == 5 || s2.Elements[s2.length - 1] < 3)
                        break;
                    pop_compute(&s1, &s2);
                }
                add_num(&s2, 4);
                break;
            }
            case '(':
                add_num(&s2, 5);
                break;
            case ')':
            {
                while (1)
                {
                    if (s2.Elements[s2.length - 1] == 5)
                        break;
                    else if (s2.length == 0)
                    {
                        cout << "Error Input!" << endl;
                        return 0;
                    }
                    pop_compute(&s1, &s2);
                }
                pop_num(&s2);
                break;
            }
            default:
                break;
            }
        }
        else if (v[i] == ' ')
        {
            if (front_is_num == 1 && v[i + 1] >= '0' && v[i + 1] <= '9')
            {
                cout << "Error Input!" << endl;
                return -1;
            }
        }
        else
        {
            cout << "Error Input!" << endl;
            return -1;
        }
        i++;
    }

    while (s2.length != 0)
    {
        pop_compute(&s1, &s2);
    }
    printf("result:%d\n", s1.Elements[0]);
    return 0;
}
