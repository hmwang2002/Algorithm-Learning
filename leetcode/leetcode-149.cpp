#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int result = 1;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> mp;
            // 用来记录垂直于x轴这一特殊情况
            int pa = 1;
            for (int j = i + 1; j < points.size(); j++)
            {
                double cur;
                if (points[j][0] - points[i][0] != 0)
                    cur = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                else
                {
                    pa++;
                    result = max(result, pa);
                    continue;
                }
                if (mp.find(cur) != mp.end())
                {
                    mp[cur]++;
                    result = max(result, mp[cur]);
                }
                else
                {
                    mp[cur] = 2;
                    result = max(result, mp[cur]);
                }
            }
        }
        return result;
    }
};