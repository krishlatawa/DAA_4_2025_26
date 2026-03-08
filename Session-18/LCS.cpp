#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> prev(n2, 0), curr(n2, 0);

        for (int i = 0; i < n2; i++)
        {
            if (text1[0] == text2[i])
            {
                prev[i] = 1;
            }
            else if (i > 0)
            {
                prev[i] = prev[i - 1];
            }
        }

        for (int i1 = 1; i1 < n1; i1++)
        {
            if (text1[i1] == text2[0])
            {
                curr[0] = 1;
            }
            else
            {
                curr[0] = prev[0];
            }
            for (int i2 = 1; i2 < n2; i2++)
            {

                if (text1[i1] == text2[i2])
                {
                    curr[i2] = 1 + prev[i2 - 1];
                }
                else
                {
                    curr[i2] = max(prev[i2], curr[i2 - 1]);
                }
            }
            prev = curr;
        }

        return prev[n2 - 1];
    }
};

int main()
{
    string text1 = "abcde", text2 = "ace";
    Solution sl;
    cout << sl.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}