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
    const static int MOD = 1e9 + 7;

    int createSortedArray(vector<int> &instructions)
    {
        auto sorted = instructions;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        Fenwick f(m + 1);
        int cost = 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            int x = instructions[i];
            int v = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
            int l = f.pre(v - 1), g = i - f.pre(v);
            cost = (cost + min(l, g)) % MOD;
            f.add(v);
        }
        return cost;
    }
};