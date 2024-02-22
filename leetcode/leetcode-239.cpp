#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> queue;
        vector<int> res(n - k + 1);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (!queue.empty() && i - k + 1 > queue.front())
            {
                queue.pop_front();
            }
            while (!queue.empty() && nums[queue.back()] <= nums[i])
            {
                queue.pop_back();
            }
            queue.push_back(i);
            if (i >= k - 1)
            {
                res[j++] = nums[queue.front()];
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution s;
    auto ans = s.maxSlidingWindow(nums, k);
    for (auto s : ans)
    {
        cout << s << " ";
    }
    return 0;
}