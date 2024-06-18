#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        int diff[102] = {0};
        for (auto &p : nums)
        {
            diff[p[0]]++;
            diff[p[1] + 1]--;
        }
        int ans = 0, s = 0;
        for (int d : diff)
        {
            s += d;
            ans += s > 0;
        }
        return ans;
    }
};