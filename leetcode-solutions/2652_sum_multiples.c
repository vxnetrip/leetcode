#include <stdio.h>

int sumOfMultiples(int n)
{
    int long result = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
        {
            result += i;
        }
    }
    return result;
}

int main()
{
    int n = 7;
    int result = sumOfMultiples(n);
    printf("%d\n", result);
    return 0;
}