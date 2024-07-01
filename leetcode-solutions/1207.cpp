#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m;

        for (int num : arr)
        {
            m[num]++;
        }

        vector<int> occur;

        for (const auto pair : m)
        {
            occur.push_back(pair.second);
        }

        unordered_set<int> t;

        for (const int num : occur)
        {
            t.insert(num);
        }
        if (t.size() == occur.size())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2};
    bool res = Solution().uniqueOccurrences(arr);
    printf("%s\n", res ? "true" : "false");
    return EXIT_SUCCESS;
}