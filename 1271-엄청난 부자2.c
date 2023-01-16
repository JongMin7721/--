#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CoN(char money[1001], char count[1001], int len, int i)
{
    return strncmp(money + i, count, len);
}

void division(char money[1001], char count[1001], char result[1001], int len, int i)
{
    int check = CoN(money, count, len, i), num, sum = 0;

    if ((int)money[i - 1] != '0' && i > 0)
    {
        money[i] = money[i] + (money[i - 1] - '0') * 10;
        money[i - 1] = '0';
    }

    while (1)
    {
        check = CoN(money, count, len, i);
        if (check == 0)
        {
            for (int j = 0; j < len; j++)
            {
                money[i + j] = '0';
            }
            sum++;
        }
        else if (check > 0)
        {
            for (int j = 0; j < len; j++)
            {
                num = money[i + j] - count[j];

                if (num < 0)
                {
                    num += 10;
                    money[i + j - 1] = money[i + j - 1] - 1;
                }

                money[i + j] = num + '0';
            }
            sum++;
        }
        else
        {
            result[i] = sum + '0';

            return;
        }
    }
}

int main(void)
{
    char money[1001], count[1001], result[1001] = {0};
    int mlen, len;

    scanf("%s %s", &money, &count);

    mlen = strlen(money);
    len = strlen(count);

    for (int i = 0; i < mlen - len + 1; i++)
    {
        division(money, count, result, len, i);
        printf("%s\n%c\t%c\n%s\n", money, money[i], money[i + 1], result);
    }

    int dd;
    for (dd = 0; result[dd] == '0'; dd++)
        ;

    printf("%s\n", result + dd);

    int cc;
    for (cc = 0; money[cc] == '0'; cc++)
        ;

    if (cc == mlen)
    {
        printf("0\n");
    }
    else
    {
        printf("%s\n", money + cc);
    }
}