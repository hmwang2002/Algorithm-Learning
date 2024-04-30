#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> preSum(n);
        for (int i = 0, sum = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                sum++;
            }
            preSum[i] = sum;
        }
        vector<int> left(n);
        for (int i = 0, l = -1; i < n; i++)
        {
            if (s[i] == '|')
            {
                l = i;
            }
            left[i] = l;
        }
        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--)
        {
            if (s[i] == '|')
            {
                r = i;
            }
            right[i] = r;
        }
        vector<int> res;
        for (auto &q : queries)
        {
            int l = right[q[0]], r = left[q[1]];
            res.push_back((l == -1 || r == -1 || l >= r) ? 0 : preSum[r] - preSum[l]);
        }
        return res;
    }
};