// 1480. Running Sum of 1d Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *runningSum(int *nums, int numsSize, int *returnSize)
{
    int *result = (int *)malloc(numsSize * sizeof(int));
    int sum = 0;
    // sliding window technique
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        result[i] = sum;
    }
    *returnSize = numsSize;
    return result;
}

int main()
{
    int onums[] = {1, 2, 3, 4};
    int numsSize = 4;
    int *nums = (int *)malloc(numsSize * sizeof(int));
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;
    int returnSize = 4;
    int *res = runningSum(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}