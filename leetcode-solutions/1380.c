#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *luckyNumbers(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int resultIter = 0;
    int *result = (int *)malloc((matrixSize + 1) * sizeof(int));
    for (int row = 0; row < matrixSize; row++) // row iterator
    {
        for (int col = 0; col < *matrixColSize; col++) // col iterator
        {
            int current_element = matrix[row][col];
            bool flag1 = false;                                                         // check if isbad
            for (int tempcol = 0; flag1 != true && tempcol < *matrixColSize; tempcol++) // temporary col for check
            {
                if (matrix[row][tempcol] < current_element)
                {
                    flag1 = true; // end checking
                }
            }
            bool flag2 = false;
            for (int temprow = 0; flag2 != true && temprow < matrixSize; temprow++)
            { // temporary row for check
                if (matrix[temprow][col] > current_element)
                {
                    flag2 = true; // end checking
                }
            }
            if (!flag1 && !flag2) // if flags are not equal to true
            {
                result[resultIter] = current_element;
                resultIter++;
            }
        }
    }
    *returnSize = resultIter;
    return result;
}

int main()
{
    int matrixSize = 3;
    int matrixColSize = 3;
    int **matrix = (int **)malloc(matrixSize * sizeof(int *));
    // int matrix[] = [[3,7,8],[9,11,13],[15,16,17]];
    for (int r = 0; r < matrixSize; r++)
    {
        matrix[r] = (int *)malloc(matrixColSize * sizeof(int));
    }
    int values[3][3] =
        {{3, 7, 8},
         {9, 11, 13},
         {15, 16, 17}};

    for (int i = 0; i < matrixColSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            matrix[i][j] = values[i][j];
        }
    }
    int returnSize = 0;
    int *resarr = luckyNumbers(matrix, matrixSize, &matrixColSize, &returnSize);

    printf("[");
    for (int y = 0; y < returnSize; y++)
    {
        printf("%d ", resarr[y]);
    }
    printf("]\n");

    return 0;
}