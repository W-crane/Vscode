#include <stdio.h>
#include <stdlib.h>

int str_to_int(char *str)
{
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        num = (str[i] - '0') + num * 10;
    }

    return num;
}

int *get_next(char *str, int length)
{
    int *next = (int *)malloc(sizeof(int) * (length + 1));
    int loc_1, loc_2, j, k;
    next[1] = 0;
    next[2] = 1;
    for (int i = 3; i <= length; i++)
    {
        loc_1 = i;
        loc_2 = loc_1 - 1;
        while (1)
        {
            for (j = loc_2 - 1, k = loc_1 - 1; j >= 1; j--, k--)
            // 也可设j、k为loc_2 loc_1 减去2 ，作为实际索引，但是需要将下方判断条件换为 j==-1
            {
                if (str[j - 1] != str[k - 1])
                    break;
            }
            if (j == 0 || loc_2 == 1)
                break;
            loc_2--;
        }
        next[i] = loc_2;
    }
    return next;
}

int KMP(char *str1, char *str2, int *next, int length1, int length2)
{
    int i, j;
    for (i = 1, j = 1; i <= length1 && j <= length2; i++, j++)
    {
        if (str1[i - 1] != str2[j - 1])
            j = next[j];
    }
    if (j > length2)
        return i - length2;
    return -1;
}

int main(int argc, char const *argv[])
{
    char str[10] = "abcabaa";
    int *next = get_next(str, 7);
    for (int i = 1; i <= 7; i++)
    {
        printf("%d\t", next[i]);
    }
    printf("\n");

    char str1[14] = "ababaa ababba";
    char str2[7] = "babaa";
    printf("%s的开头在%s的第%d个位置\n", str2, str1, KMP(str1, str2, get_next(str2, 5), 13, 5));
    return 0;
}
