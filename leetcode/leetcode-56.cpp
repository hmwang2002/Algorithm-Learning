#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            if (end >= intervals[i + 1][0])
            {
                end = max(end, intervals[i + 1][1]);
            }
            else
            {
                ret.push_back({start, end});
                start = intervals[i + 1][0];
                end = intervals[i + 1][1];
            }
        }
        ret.push_back({start, end});
        return ret;
    }
};