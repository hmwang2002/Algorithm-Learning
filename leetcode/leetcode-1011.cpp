#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        auto check = [&](int x)
        {
            int sum = 0;
            int t = 1;
            for (int i = 0; i < weights.size(); i++)
            {
                sum += weights[i];
                if (sum > x)
                {
                    sum = weights[i];
                    t++;
                }
            }
            if (t > days)
                return false;
            return true;
        };

        int r = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};