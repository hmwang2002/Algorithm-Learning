#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Boyer-Moore 投票算法
    int majorityElement(vector<int> &nums)
    {
        int candidate = -1;
        int cnt = 0;
        for(int num : nums) {
            if(num == candidate) {
                cnt++;
            } else if(--cnt < 0) {
                candidate = num;
                cnt = 1;
            }
        }
        return candidate;
    }
};