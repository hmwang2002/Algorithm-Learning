#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        int cnt = 1;
        int point = nums[0] + nums[1];
        for (int i = 2; i < nums.size() - 1; i += 2)
        {
            int p = nums[i] + nums[i + 1];
            if (p == point)
                cnt++;
            else
                break;
        }
        return cnt;
    }
};