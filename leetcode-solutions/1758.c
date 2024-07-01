#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int minOperations(char *s)
{
    int len = strlen(s);

    int zeroOnEven = 0;
    int zeroOnOdd = 0;
    int oneOnEven = 0;
    int oneOnOdd = 0;

    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '0')
            {
                zeroOnEven++;
            }
            else
            {
                oneOnEven++;
            }
        }
        else
        {
            if (s[i] == '0')
            {
                zeroOnOdd++;
            }
            else
            {
                oneOnOdd++;
            }
        }
    }
    int c1 = zeroOnEven + oneOnOdd;
    int c2 = oneOnEven + zeroOnOdd;
    if (c1 < c2)
    {
        return c1;
    }
    else
    {
        return c2;
    }
}

int main()
{
    int charSize = 5;
    char *buff = (char *)malloc(charSize * sizeof(char));
    strcpy(buff, "0100");
    int result = minOperations(buff);
    printf("%d\n", result);
    return 0;
}