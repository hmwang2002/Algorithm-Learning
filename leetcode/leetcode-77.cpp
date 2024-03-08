#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> v;

public:
    void backtracking(int n, int k, int index)
    {
        if (v.size() == k)
        {
            res.push_back(v);
            return;
        }
        if (index > n)
            return;
        for (int i = index; i <= n; i++)
        {
            v.push_back(i);
            backtracking(n, k, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return res;
    }
};