#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> parent;

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        int n = deadline.size();

        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++)
            jobs.push_back({profit[i], deadline[i]});

        // Sort by profit descending
        sort(jobs.begin(), jobs.end(), greater<>());

        int max_deadline = 0;
        for (int d : deadline)
            max_deadline = max(max_deadline, d);

        parent.resize(max_deadline + 1);
        for (int i = 0; i <= max_deadline; i++)
            parent[i] = i;

        int cnt = 0, max_profit = 0;

        for (auto &job : jobs)
        {
            int prof = job.first;
            int d = job.second;

            int available = find(d);
            if (available > 0)
            {
                cnt++;
                max_profit += prof;
                parent[available] = find(available - 1); // union
            }
        }

        return {cnt, max_profit};
    }
};

int main()
{

    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};

    Solution sl;
    for (auto a : sl.jobSequencing(deadline, profit))
    {
        cout << a << " ";
    }
    return 0;
}