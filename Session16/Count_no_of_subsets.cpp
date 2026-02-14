#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
    {

        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        solve(nums, output, index + 1, ans);

        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> output;
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    Solution sl;
    for (auto a : sl.subsets(nums))
    {
        cout << "[";
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}