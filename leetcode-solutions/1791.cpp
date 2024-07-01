#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < edges.size(); i++)
        {
            for (int j = 0; j < edges[i].size(); j++)
            {
                map[edges[i][j]]++;
            }
        }

        for (const auto &elem : map)
        {
            if (elem.second == edges.size())
            {
                return elem.first;
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    int result = Solution().findCenter(edges);
    printf("%d\n", result);
    return EXIT_SUCCESS;
}