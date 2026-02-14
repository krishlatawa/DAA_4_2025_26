#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;

        int prev1 = 3;
        int prev2 = 2;
        int cur = 0;

        for (int i = 3; i < n; i++)
        {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return cur;
    }
};
int main()
{

    int n = 2;
    Solution sl;
    cout << "No. of ways = " << sl.climbStairs(n) << endl;
    return 0;
}