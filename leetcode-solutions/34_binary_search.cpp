#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, bool isSearchingLeft)
    {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                idx = mid;
                if (isSearchingLeft)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return idx;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result = {-1, -1};
        result[1] = binarySearch(nums, target, true);
        result[0] = binarySearch(nums, target, false);
        return result;
    }
};

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = Solution().searchRange(nums, target);
    cout << res[0] << endl;
    cout << res[1] << endl;
    return EXIT_SUCCESS;
}