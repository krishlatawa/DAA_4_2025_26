#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjlist;
vector<int> path;
vector<int> vis;
int V;

bool hasedge(int u, int v)
{
    for (int x : adjlist[u])
    {
        if (x == v)
        {
            return true;
        }
    }
    return false;
}
bool solve(int u, int cnt)
{
    if (cnt == V)
    {
        return hasedge(u, path[0]);
    }
    for (int x : adjlist[u])
    {
        if (!vis[x])
        {
            vis[x] = true;
            path.push_back(x);
            if (solve(x, cnt + 1))
                return true;

            vis[x] = false;
            path.pop_back();
        }
    }
}
int main()
{

    int t = 1;
    while (t--)
    {
        V = 5;
        adjlist = {
            {1, 3},
            {0, 2, 3, 4},
            {1, 4},
            {0, 1, 4},
            {1, 2, 3}};
        vis.assign(V, false);
        path.push_back(0);
        vis[0] = true;
        if (solve(0, 1))
        {
            cout << "Hamiltonian Path found!" << endl;
            for (int i : path)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Hamiltonian Path not found!" << endl;
        }
    }

    return 0;
}