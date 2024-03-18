#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while(fast < nums.size()) {
            if(nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }
    }
};