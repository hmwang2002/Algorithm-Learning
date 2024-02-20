#include <bits/stdc++.h>

using namespace std;

struct Node
{
    unordered_map<int, Node *> son;
    int cnt = 0;
};

class Solution
{
public:
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        long long ans = 0;
        Node *root = new Node();
        for (string &s : words)
        {
            int n = s.length();
            auto cur = root;
            for (int i = 0; i < n; i++)
            {
                int p = (int)(s[i] - 'a') << 5 | (s[n - 1 - i] - 'a');
                if (cur->son[p] == nullptr)
                {
                    cur->son[p] = new Node();
                }
                cur = cur->son[p];
                ans += cur->cnt;
            }
            cur->cnt++;
        }
        return ans;
    }
};