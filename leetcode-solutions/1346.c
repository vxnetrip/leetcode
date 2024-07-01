#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkIfExist(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            if (arr[i] == arr[j] * 2 || arr[i] * 2 == arr[j])
            {
                if (i != j)
                {
                    return true;
                }
            }
        }
    }
    return false;
}