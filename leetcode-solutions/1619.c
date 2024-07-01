#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubbleSort(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

double trimMean(int *arr, int arrSize)
{
    bubbleSort(arr, arrSize);
    int m = (int)(0.05 * arrSize);

    double s = 0;
    for (int i = m; i < arrSize - m; i++)
    {
        s += arr[i];
    }

    double mean = s / (arrSize - 2 * m);

    return mean;
}

int main()
{
    int arrSize = 20;
    int values[] = {6, 0, 7, 0, 7, 5, 7, 8, 3, 4, 0, 7, 8, 1, 6, 8, 1, 1, 2, 4, 8, 1, 9, 5, 4, 3, 8, 5, 10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4};
    int *arr = (int *)malloc(arrSize * sizeof(values));
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = values[i];
    }

    double res = trimMean(arr, arrSize);

    printf("%f\n", res);

    printf("[");
    for (int d = 0; d < arrSize; d++)
    {
        printf("%d ", arr[d]);
    }
    printf("]\n");

    return 0;
}