#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> d;
        for(int x : nums) {
            auto it = lower_bound(d.begin(), d.end(), x);
            if(it == d.end()) {
                d.push_back(x);
            } else {
                *it = x;
            }
        }
        return d.size();
    }
};