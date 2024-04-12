#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i <= r; i++) {
            while(i <= r && nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
            }
            if(nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
            }
        }
    }
};