#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void toBaseK(int k, int num, char *memory)
{
    int i = 0;
    bool negative = num < 0;
    if (negative)
    {
        num = -num;
    }

    do
    {
        int remainder = num % k;
        memory[i++] = remainder + '0';
        num /= k;
    } while (num != 0);

    memory[i] = '\0';

    for (int start = 0, end = i - 1; i < end; start++, end--)
    {
        char tmp = memory[start];
        memory[start] = memory[end];
        memory[end] = tmp;
    }
}

int sumBase(int n, int k)
{
    int i = 0;
    char *memory = (char *)malloc(20 * sizeof(char));
    toBaseK(k, n, memory);
    printf("%s\n", memory);
    int negative = false;
    int result = 0;

    if (memory[i] == '-')
    {
        negative = true;
        i++;
    }

    for (int c = 0; memory[c] != '\0'; c++)
    {
        result += memory[c] - '0';
    }

    return result;
}

int main()
{
    int n = 34;
    int k = 6;
    int result = sumBase(n, k);
    printf("%d\n", result);
    return EXIT_SUCCESS;
}