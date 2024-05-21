#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int a = 0, b = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                a++;
                b++;
                cur = max(cur, a);
            }
            else
            {
                a = b;
                b = 0;
            }
        }
        if(cur == nums.size())
            cur--;
        return cur;
    }
};