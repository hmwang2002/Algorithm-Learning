#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const auto &u, const auto &v)
             { return u[1] < v[1]; });
        int cnt = 0, n = points.size();
        int right = points[0][1];
        for (int i = 1; i < n; i++)
        {
            if (points[i][0] <= right)
            {
                cnt++;
            }
            else
            {
                right = points[i][1];
            }
        }
        return n - cnt;
    }
};