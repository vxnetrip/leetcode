#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *generateTheString(int n)
{
    char *buff = (char *)malloc((n + 1) * sizeof(char));
    if (n % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            buff[i] = 'a';
        }
    }
    else
    {
        for (int i = 0; i < (n - 1); i++)
        {
            buff[i] = 'a';
        }
        buff[n - 1] = 'b';
    }
    buff[n] = '\0';
    return buff;
}

int main()
{
    int n = 3;
    char *result = generateTheString(n);
    printf("%s\n", result);
    return 0;
}