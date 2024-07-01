#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// bool isSub(char *pattern, char *word)
//  {
//      int pindex = 0;
//      int windex = 0;

//     while (word[windex] != '\0')
//     {
//         if (word[windex] == pattern[pindex])
//         {
//             pindex++;
//             if (pattern[pindex] == '\0')
//             {
//                 return true;
//             }
//         }
//         else
//         {
//             if (pindex != 0)
//             {
//                 windex -= pindex;
//                 pindex = 0;
//             }
//         }
//         windex++;
//     }
//     return false;
// }

bool isSub(char *pattern, char *word)
{
    int pindex = 0;
    int windex = 0;

    while (word[windex] != '\0')
    {
        if (word[windex] == pattern[pindex])
        {
            pindex++;
            if (pattern[pindex] == '\0')
            {
                return true;
            }
        }
        else
        {
            if (pindex != 0)
            {
                windex -= pindex;
                pindex = 0;
            }
        }
        windex++;
    }
    return false;
}

int numOfStrings(char **patterns, int patternsSize, char *word)
{
    int c = 0;
    for (int f = 0; f < patternsSize; f++)
    {
        if (isSub(patterns[f], word) == true)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    char *original_patterns[] = {"a", "abc", "bc", "d"}; // Array of pointers to string literals
    char *original_word = "abc";
    int patternsSize = 4;

    // Allocate memory for pointers to the patterns
    char **patterns = (char **)malloc(patternsSize * sizeof(char *));
    if (patterns == NULL)
    {
        perror("Failed to allocate memory for patterns");
        return EXIT_FAILURE;
    }

    // Copy each string into newly allocated memory
    for (int f = 0; f < patternsSize; f++)
    {
        patterns[f] = (char *)malloc(strlen(original_patterns[f]) + 1); // +1 for the null terminator
        if (patterns[f] == NULL)
        {
            perror("Failed to allocate memory for a pattern");
            // Clean up previously allocated memory
            for (int j = 0; j < f; j++)
            {
                free(patterns[j]);
            }
            free(patterns);
            return EXIT_FAILURE;
        }
        strcpy(patterns[f], original_patterns[f]);
    }

    // Allocate memory for the word
    char *word = (char *)malloc(strlen(original_word) + 1);
    if (word == NULL)
    {
        perror("Failed to allocate memory for word");
        // Clean up pattern memory
        for (int j = 0; j < patternsSize; j++)
        {
            free(patterns[j]);
        }
        free(patterns);
        return EXIT_FAILURE;
    }
    strcpy(word, original_word);

    // Call numOfStrings to find how many patterns are substrings of word
    int result = numOfStrings(patterns, patternsSize, word);
    printf("%d\n", result);

    // Clean up memory
    for (int j = 0; j < patternsSize; j++)
    {
        free(patterns[j]);
    }
    free(patterns);
    free(word);

    return EXIT_SUCCESS;
}
