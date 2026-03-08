#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // min(not-take,1+dp[i][j-i])
        int n = coins.size();

        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int take = INT_MAX;
                if (j >= coins[i - 1])
                {
                    take = 1 + dp[i][j - coins[i - 1]];
                }
                dp[i][j] = min(dp[i - 1][j], take);
            }
        }

        return dp[n][amount] == INF ? -1 : dp[n][amount];
    }
};

int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution sl;
    cout << sl.coinChange(coins, amount) << endl;
    return 0;
}