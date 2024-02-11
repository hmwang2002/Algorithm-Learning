#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int left = newInterval[0], right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto &v : intervals)
        {
            if (v[0] > right)
            {
                if (!placed)
                {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(v);
            }
            else if (v[1] < left)
            {
                ans.push_back(v);
            }
            else
            {
                left = min(left, v[0]);
                right = max(right, v[1]);
            }
        }
        if (!placed)
        {
            ans.push_back({left, right});
        }
        return ans;
    }
};