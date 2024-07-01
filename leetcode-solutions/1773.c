#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int countMatches(char ***items, int itemsSize, int *itemsColSize, char *ruleKey, char *ruleValue)
{
    int count = 0;
    int index = -1;

    if (strcmp(ruleKey, "type") == 0)
    {
        index = 0;
    }
    else if (strcmp(ruleKey, "color") == 0)
    {
        index = 1;
    }
    else if (strcmp(ruleKey, "name") == 0)
    {
        index = 2;
    }

    for (int i = 0; i < itemsSize; i++)
    {
        if (strcmp(ruleValue, items[i][index]) == 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    // type, color, name
    int itemsSize = 3;
    int itemsColSize = 3;
    char *ruleKey = "type";
    char *ruleValue = "phone";
    char *staticitems[3][3] = {
        {"phone", "blue", "pixel"},
        {"computer", "silver", "phone"},
        {"phone", "gold", "iphone"}};
    char ***items = (char ***)malloc(itemsSize * sizeof(char **));
    for (int i = 0; i < itemsSize; i++)
    {
        items[i] = (char **)malloc(itemsColSize * sizeof(char *));
        for (int j = 0; j < itemsSize; j++)
        {
            items[i][j] = (char *)malloc((strlen(staticitems[i][j]) + 1) * sizeof(char));
            strcpy(items[i][j], staticitems[i][j]);
        }
    }

    int result = countMatches(items, itemsSize, &itemsColSize, ruleKey, ruleValue);

    printf("%d\n", result);

    // Example usage to print the items
    // for (int i = 0; i < itemsSize; i++)
    // {
    //     for (int j = 0; j < itemsColSize; j++)
    //     {
    //         printf("%s ", items[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}