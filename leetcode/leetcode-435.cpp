#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v)
             { return u[1] < v[1]; });
        int n = intervals.size();
        int right = intervals[0][1];
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < right)
            {
                cnt++;
            }
            else
            {
                right = intervals[i][1];
            }
        }
        return cnt;
    }
};