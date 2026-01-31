#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int size;
    vector<vector<string>> solutions;
    vector<string> create_board(const vector<int> &path)
    {
        vector<string> board;
        for (size_t i = 0; i < size; i++)
        {
            string r(size, '.');
            r[path[i]] = 'Q';
            board.push_back(r);
        }
        return board;
    }
    void backtrack(int row, unordered_set<int> diag1, unordered_set<int> diag2, unordered_set<int> col, vector<int> path)
    {
        if (row == size)
        {
            solutions.push_back(create_board(path));
            return;
        }
        for (size_t i = 0; i < size; i++)
        {
            if ((col.find(i) == col.end()) && (diag1.find(row - i) == diag1.end()) && (diag2.find(row + i) == diag2.end()))
            {
                path.push_back(i);
                col.insert(i);
                diag1.insert(row - i);
                diag2.insert(row + i);
                backtrack(row + 1, diag1, diag2, col, path);
                path.pop_back();
                col.erase(i);
                diag1.erase(row - i);
                diag2.erase(row + i);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        size = n;
        backtrack(0, unordered_set<int>(), unordered_set<int>(), unordered_set<int>(), {});
        return solutions;
    }
};
int main()
{
    Solution sol;
    int n = 4;
    vector<vector<string>> result = sol.solveNQueens(n);
    for (const auto &board : result)
    {
        for (const auto &row : board)
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}