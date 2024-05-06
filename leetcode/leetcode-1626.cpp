#include <bits/stdc++.h>

using namespace std;

class Solution
{
    static constexpr int MX = 1000;
    int t[MX + 1];

    int query(int i)
    {
        int mx = 0;
        for (; i; i &= i - 1)
        {
            mx = max(mx, t[i]);
        }
        return mx;
    }

    void update(int i, int mx)
    {
        for (; i <= MX; i += i & -i)
        {
            t[i] = max(t[i], mx);
        }
    }

public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        pair<int, int> a[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = {scores[i], ages[i]};
        }
        sort(a, a + n);

        for (auto &[score, age] : a)
        {
            update(age, query(age) + score);
        }
        return query(MX);
    }
};