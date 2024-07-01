#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *leftRightDifference(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int left = 0;
    int right = 0;
    for (int i = 0; i < numsSize; i++)
    {
        right += nums[i];
    }

    int *result = (int *)malloc((*returnSize) * sizeof(int));

    // int *leftsum = (int *)malloc(numsSize * sizeof(int));
    // int *rightsum = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        right -= nums[i];
        // leftsum[i] = left;
        // rightsum[i] = right;

        result[i] = abs(left - right);

        left += nums[i];
    }

    return result;
}

int main()
{
    int original[] = {10, 4, 8, 3};
    int numsSize = 4;
    int *nums = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = original[i];
    }

    int returnSize;

    int *result = leftRightDifference(nums, numsSize, &returnSize);
    printf("[");

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("]\n");
    return 0;
}