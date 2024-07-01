#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// bubble sort
void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int *targetIndices(int *nums, int numsSize, int target, int *returnSize)
{
    bubbleSort(nums, numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            (*returnSize)++;
        }
    }

    int *result = (int *)malloc((*returnSize) * sizeof(int));

    int retindex = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            result[retindex] = i;
            retindex++;
        }
    }

    return result;
}

int main()
{
    int nums[] = {1, 2, 5, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;
    int returnSize;

    int *result = targetIndices(nums, numsSize, target, &returnSize);

    if (result != NULL)
    {
        for (int i = 0; i < returnSize; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }
    else
    {
        printf("[]\n");
    }

    return 0;
}