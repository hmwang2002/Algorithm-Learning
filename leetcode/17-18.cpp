#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> shortestSeq(vector<int> &big, vector<int> &small)
    {
        unordered_map<int, int> cnt;
        for (int x : small)
            cnt[x]++;
        int n = small.size();
        int l = 0, res = INT_MAX, res_l = 0;
        for (int r = 0; r < big.size(); r++)
        {
            if (cnt[big[r]] > 0)
            {
                n--;
            }
            cnt[big[r]]--;
            if (n == 0)
            {
                while (cnt[big[l]] < 0)
                {
                    cnt[big[l++]]++;
                }
                if (r - l + 1 < res)
                {
                    res = r - l + 1;
                    res_l = l;
                }
                cnt[big[l++]]++;
                n++;
            }
        }
        return res == INT_MAX ? vector<int>() : vector<int>{res_l, res_l + res - 1};
    }
};