#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string greatestLetter(string s)
    {
        unordered_set<char> st;
        string ans;
        char temp = ' ';

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                st.insert(s[i]);
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                if ((st.find(s[i] + 32) != st.end()))
                    temp = max(temp, s[i]);
        }

        if (temp != ' ')
        {
            ans += temp;
        }

        return ans;
    }
};

int main()
{
    string s = "lEeTcOdE";
    Solution sol;
    string res = sol.greatestLetter(s);
    cout << res << endl;
    return EXIT_SUCCESS;
}