#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int u, int cnt, int V, vector<bool> &vis, vector<int> &path, vector<vector<int>> &adjlist)
    {
        if (cnt == V)
        {
            return true;
        }
        for (int x : adjlist[u])
        {
            if (!vis[x])
            {
                vis[x] = true;
                path.push_back(x);
                if (solve(x, cnt + 1, V, vis, path, adjlist))
                    return true;

                vis[x] = false;
                path.pop_back();
            }
        }
        return false;
    }
    bool check(int n, int m, vector<vector<int>> edges)
    {
        vector<vector<int>> adjlist(n + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            int temp = edges[i][0];
            int temp2 = edges[i][1];
            adjlist[temp].push_back(temp2);
            adjlist[temp2].push_back(temp);
        }

        for (int start = 1; start <= n; start++)
        {
            vector<int> path;
            vector<bool> vis(n + 1, false);

            vis[start] = true;
            path.push_back(start);
            if (solve(start, 1, n, vis, path, adjlist))
                return true;
        }
        return false;
    }
};

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {2, 4}};
    Solution sl;
    if (sl.check(n, m, edges))
    {
        cout << "Path Exsists!" << endl;
    }
    else
    {
        cout << "Path doesn't Exsists!" << endl;
    }
    return 0;
}