#include <iostream>
#include <vector>
#include <limits>

#ifndef INT16_MAX
#define INT16_MAX 32767
#endif

using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    int minimumOperations(vector<int> &nums)
    {
        bubbleSort(nums);

        int minval = INT16_MAX;
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            else
            {
                for (int j = i + 1; j < n; j++)
                {
                    minval = min(nums[i], nums[j]);
                }

                for (int j = i; j < n; j++)
                {
                    nums[j] -= minval;
                }

                count++;
            }
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {1, 5, 0, 3, 5};
    int re = Solution().minimumOperations(nums);
    printf("%d\n", re);
    return EXIT_SUCCESS;
}