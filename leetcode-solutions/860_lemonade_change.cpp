#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fiveBills = 0;
        int tenBills = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            cout << bills[i] << endl;
            switch (bills[i])
            {
            case 5:
            {
                fiveBills++;
                break;
            }

            case 10:
            {
                tenBills++;
                if (fiveBills > 0)
                {
                    fiveBills--;
                    break;
                }
                else
                {
                    return false;
                }
            }

            case 20:
                if (tenBills > 0 && fiveBills > 0)
                {
                    tenBills--;
                    fiveBills--;
                    break;
                }
                else if (fiveBills >= 3)
                {
                    fiveBills -= 3;
                    break;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20, 20, 20};
    bool res = Solution().lemonadeChange(bills);
    printf("%s", res ? "true" : "false");
    return EXIT_SUCCESS;
}