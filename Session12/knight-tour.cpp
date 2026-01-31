#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dx{-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> dy{1, 2, 2, 1, -1, -2, -2, -1};
    bool isSafe(vector<vector<int>> &grid, int i, int j, int n)
    {
        return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == -1;
    }
    bool f(vector<vector<int>> &grid, int i, int j, int n, int count)
    {
        if (count == n * n - 1)
            return true;
        for (int k = 0; k < 8; k++)
        {
            int r = i + dx[k];
            int c = j + dy[k];
            if (isSafe(grid, r, c, n))
            {
                grid[r][c] = count + 1;
                if (f(grid, r, c, n, count + 1))
                    return true;
                grid[r][c] = -1;
            }
        }
        return false;
    }
    vector<vector<int>> knightTour(int n)
    {
        vector<vector<int>> grid;
        grid.resize(n, vector<int>(n, -1));
        grid[0][0] = 0;
        if (f(grid, 0, 0, n, 0))
            return grid;
        return {};
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> result = sol.knightTour(n);
    if (!result.empty())
    {
        for (const auto &row : result)
        {
            for (const auto &cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution found." << endl;
    }
    return 0;
}