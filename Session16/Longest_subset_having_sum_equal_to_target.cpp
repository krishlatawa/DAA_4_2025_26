#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int sum, vector<int> &arr, int target,
              vector<vector<int>> &dp)
    {

        if (sum == target)
            return 0;
        if (i == arr.size())
            return -1;

        if (dp[i][sum] != -2)
            return dp[i][sum];

        int notTake = solve(i + 1, sum, arr, target, dp);

        int take = -1;
        if (sum + arr[i] <= target)
        {
            int temp = solve(i + 1, sum + arr[i], arr, target, dp);
            if (temp != -1)
                take = 1 + temp;
        }

        return dp[i][sum] = max(take, notTake);
    }

    vector<int> longestSubsetWithTargetSum(vector<int> &arr, int target)
    {

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -2));

        int maxLen = solve(0, 0, arr, target, dp);

        vector<int> subset;

        if (maxLen <= 0)
            return subset;

        int i = 0, sum = 0;

        while (i < n && sum < target)
        {

            int notTake = solve(i + 1, sum, arr, target, dp);

            int take = -1;
            if (sum + arr[i] <= target)
            {
                int temp = solve(i + 1, sum + arr[i], arr, target, dp);
                if (temp != -1)
                    take = 1 + temp;
            }

            if (take >= notTake && take != -1)
            {
                subset.push_back(arr[i]);
                sum += arr[i];
            }

            i++;
        }

        return subset;
    }
};

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;
    Solution sl;
    for (auto a : sl.longestSubsetWithTargetSum(arr, target))
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}