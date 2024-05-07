#include <bits/stdc++.h>

using namespace std;

class Fenwick
{
    vector<int> tree;

public:
    Fenwick(int n) : tree(n) {}

    void add(int i)
    {
        while (i < tree.size())
        {
            tree[i]++;
            i += i & -i;
        }
    }

    int pre(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += tree[i];
            i &= i - 1;
        }
        return s;
    }
};

class Solution
{
public:
    int reversePairs(vector<int> &record)
    {
        vector<int> tmp = record;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        int m = tmp.size();

        Fenwick f(m + 1);
        int ans = 0;
        for (int i = 0; i < record.size(); i++)
        {
            int x = record[i];
            int v = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin() + 1;
            ans += i - f.pre(v);
            f.add(v);
        }
        return ans;
    }
};