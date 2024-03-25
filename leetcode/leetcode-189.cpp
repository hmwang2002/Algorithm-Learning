#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    // void rotate(vector<int> &nums, int k)
    // {
    //     int n = nums.size();
    //     k = k % n;
    //     int count = __gcd(k, n);
    //     for (int start = 0; start < count; ++start)
    //     {
    //         int current = start;
    //         int prev = nums[start];
    //         do
    //         {
    //             int next = (current + k) % n;
    //             swap(nums[next], prev);
    //             current = next;
    //         } while (start != current);
    //     }
    // }
};