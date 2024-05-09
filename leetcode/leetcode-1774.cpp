#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        vector<bool> f(target + 1);
        int ans = INT_MAX;
        for (int &x : baseCosts)
        {
            if (x > target)
                ans = min(ans, x);
            else
                f[x] = true;
        }
        for (int &x : toppingCosts)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int j = target; j >= 0; j--)
                {
                    if (f[j] && j + x > target)
                        ans = min(ans, j + x);
                    if (j >= x)
                        f[j] = f[j] | f[j - x];
                }
            }
        }
        for (int i = 0; i <= ans - target && i <= target; i++)
        {
            if (f[target - i])
                return target - i;
        }
        return ans;
    }
};