#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (m > bloomDay.size() / k)
        {
            return -1;
        }
        int l = *min_element(bloomDay.begin(), bloomDay.end()), r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l + 1 < r)
        {
            int days = l + (r - l) / 2;
            if (canMake(bloomDay, days, m, k))
            {
                r = days;
            }
            else
            {
                l = days;
            }
        }
        return r;
    }

    bool canMake(vector<int> &bloomDays, int days, int m, int k)
    {
        int n = bloomDays.size();
        int bonquets = 0, flowers = 0;
        for (int i = 0; i < n && bonquets < m; i++)
        {
            if (bloomDays[i] <= days)
            {
                flowers++;
                if (flowers == k)
                {
                    bonquets++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }
        return bonquets >= m;
    }
};