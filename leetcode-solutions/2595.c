#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_SIZE 32

char *toBinary(int n)
{
    if (n == 0)
    {
        char *zero = (char *)malloc(2 * sizeof(char));
        strcpy(zero, "0");
        return zero;
    }

    char *binary = (char *)malloc((INT_SIZE + 1) * sizeof(char));
    int i = 0;

    while (n > 0)
    {
        int remainder = n % 2;
        binary[i] = remainder + '0';
        n /= 2;
        i++;
    }
    binary[i] = '\0';

    return binary;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *evenOddBit(int n, int *returnSize)
{
    *returnSize = 2;
    int *returnArr = (int *)malloc((*returnSize) * sizeof(int));
    returnArr[0] = 0; // Even bit count
    returnArr[1] = 0; // Odd bit count

    char *binary = toBinary(n);

    int len = strlen(binary);

    for (int i = 0; i < len; i++)
    {
        if (binary[i] == '1')
        {
            if (i % 2 == 0)
            {
                returnArr[0]++; // Count even index bits
            }
            else
            {
                returnArr[1]++; // Count odd index bits
            }
        }
    }
    free(binary);
    return returnArr;
}

int main()
{
    int returnSize;
    int n = 50;
    int *arr = evenOddBit(n, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d", arr[i]);
        if (i < returnSize - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");

    free(arr);
    return EXIT_SUCCESS;
}