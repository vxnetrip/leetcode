#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int first = -1;
    int last = -1;

    int i = 0;
    while (i < numsSize && nums[i] <= target)
    {
        if (nums[i] == target)
        {
            if (first == -1)
            {
                first = i;
            }
        }
        i++;
    }
    // printf("Last: %d\n", nums[i]);
    if (i > 0 && nums[i - 1] == target)
        last = i - 1;

    int *result = (int *)malloc((*returnSize) * sizeof(int));

    result[0] = first;
    result[1] = last;

    return result;
}

int main()
{
    int prenums[] = {5, 7, 7, 8, 8, 10};
    int numsSize = sizeof(prenums) / sizeof(prenums[0]);
    int *nums = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = prenums[i];
    }
    int target = 6;

    int returnSize;

    int *result = searchRange(nums, numsSize, target, &returnSize);

    for (int y = 0; y < returnSize; y++)
    {
        printf("%d, ", result[y]);
    }

    return EXIT_SUCCESS;
}