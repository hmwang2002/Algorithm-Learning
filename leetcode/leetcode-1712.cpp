#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const static int mod = 1e9 + 7;

    int waysToSplit(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        vector<long long> sm(n + 1);
        for (int i = 0; i < n; i++)
        {
            sm[i + 1] = sm[i] + nums[i];
        }
        int l1 = 1, l2 = 1;
        for (int r = 2; r < n; r++)
        {
            while (l1 < r && sm[l1] <= sm[r] - sm[l1])
            {
                l1++;
            }
            while (l2 < l1 && sm[r] - sm[l2] > sm[n] - sm[r])
            {
                l2++;
            }
            ans = (ans + l1 - l2) % mod;
        }
        return ans;
    }
};