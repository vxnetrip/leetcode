#include <stdio.h>
#include <stdlib.h>

void insert(int *arr, int index, int number)
{
    for (int i = index)
}

void duplicateZeros(int *arr, int arrSize)
{
}

int main()
{
    int original_arr[] = {1, 0, 2, 3, 0, 4, 5, 0};
    int size = 8;
    int *allocated_array = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        allocated_array[i] = original_arr[i];
        // printf("%d", allocated_array[i]);
    }

    int *result = duplicateZeros(allocated_array, size);
    return 0;
}