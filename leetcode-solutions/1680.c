#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007 // Define the modulus value to avoid overflow

int concatenatedBinary(int n)
{
    long result = 0;
    int length = 0;

    for (int i = 1; i <= n; i++)
    {

        if ((i & (i - 1)) == 0)
        {
            length++;
        }

        result = ((result << length) + i) % (long)MOD;
    }

    return (int)result;
}

int main()
{
    int n = 3;
    int result = concatenatedBinary(n);
    printf("%d\n", result);
    return EXIT_SUCCESS;
}