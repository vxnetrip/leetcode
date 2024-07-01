#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sortedArr;
        sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int rank = 1;

        unordered_map<int, int> hashmap;

        for (int num : sortedArr)
        {
            if (hashmap.find(num) == hashmap.end())
            {
                hashmap[num] = rank++;
            }
        }

        for (int &num : arr)
        {
            num = hashmap[num];
        }

        return arr;
    }
};