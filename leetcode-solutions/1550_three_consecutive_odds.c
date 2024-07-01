#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool threeConsecutiveOdds(int *arr, int arrSize)
{
    int c = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 != 0)
        {
            c++;
        }
        else
        {
            c = 0;
        }
        if (c == 3)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arrSize = 6;
    int original[] = {2, 6, 4, 1, 3, 5};
    int *arr = (int *)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = original[i];
    }
    bool res = threeConsecutiveOdds(arr, arrSize);
    printf("%s\n", res ? "true" : "false");
    return 0;
}