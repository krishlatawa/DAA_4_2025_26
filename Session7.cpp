#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int freq;
        Node *left, *right;

        Node(int f)
        {
            freq = f;
            left = right = NULL;
        }
    };

    struct cmp
    {
        bool operator()(Node *a, Node *b)
        {
            return a->freq > b->freq;
        }
    };

    void generate(Node *root, string code, vector<string> &res)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            res.push_back(code);
            return;
        }

        generate(root->left, code + "0", res);
        generate(root->right, code + "1", res);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;

        for (int i = 0; i < N; i++)
            pq.push(new Node(f[i]));

        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();

            Node *merged = new Node(left->freq + right->freq);
            merged->left = left;
            merged->right = right;

            pq.push(merged);
        }

        vector<string> res;
        generate(pq.top(), "", res);

        return res;
    }
};

int main()
{

    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = 6;

    Solution sl;
    for (auto a : sl.huffmanCodes(S, f, N))
    {
        cout << a << " ";
    }
    return 0;

}
