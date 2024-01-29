#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int duplicateInArray(vector<int> &nums)
    {
        int n = nums.size();
        int buckets[n];
        memset(buckets, 0, sizeof buckets);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0 || nums[i] >= n)
                return -1;
            buckets[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (buckets[i] > 1)
                return i;
        }
        return -1;
    }
};