#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return nums.size();
        int slow = 2, fast = 2;
        while (fast < n)
        {
            if (nums[slow - 2] != nums[fast])
            {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
};