#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *distributeCandies(int candies, int num_people, int *returnSize)
{
    int *array = (int *)malloc(num_people * sizeof(int));
    *returnSize = num_people;

    for (int j = 0; j < num_people; j++)
    {
        array[j] = 0;
    }

    int cur_person = 0;
    int i = 0;
    while (candies > 0)
    {
        int to_distribute = 1 + i;
        if (to_distribute > candies)
        {
            to_distribute = candies;
        }
        array[cur_person] += to_distribute;
        candies -= to_distribute;

        i++;
        if (cur_person == num_people - 1)
        {
            cur_person = 0;
        }
        else
        {
            cur_person++;
        }
    }
    return array;
}

int main()
{

    int candies = 7;
    int num_people = 4;
    int returnSize;
    int *result = distributeCandies(candies, num_people, &returnSize);
    printf("{");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d, ", result[i]);
    }
    printf("}\n");
    return 0;
}