#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007

char *toBinary(int n)
{
    if (n == 0)
    {
        char *zero = (char *)malloc(2 * sizeof(char));
        strcpy(zero, "0");
        return zero;
    }

    int size = sizeof(int) * CHAR_BIT;

    char *b = (char *)malloc((size + 1) * sizeof(char));
    int i = 0;

    while (n > 0)
    {
        int remainder = n % 2;
        b[i] = remainder + '0';
        n /= 2;
        i++;
    }

    b[i] = '\0';

    int len = i;
    for (int j = 0; j < len / 2; j++)
    {
        char temp = b[j];
        b[j] = b[len - j - 1];
        b[len - j - 1] = temp;
    }

    return b;
}

int concatenatedBinary(int n)
{
    char *bin = (char *)malloc(1);
    bin[0] = '\0';
    int binSize = 1;

    for (int i = 1; i <= n; i++)
    {
        char *bi = toBinary(i);
        int biLen = strlen(bi);
        binSize += biLen;
        bin = (char *)realloc(bin, binSize * sizeof(char));
        strcat(bin, bi);
        free(bi);
    }

    int result = 0;
    for (int i = 0; bin[i] != '\0'; i++)
    {
        result = (result * 2 + (bin[i] - '0')) % MOD;
    }

    free(bin);

    return result;
}

int main()
{
    int n = 12;

    int result = concatenatedBinary(n);
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}