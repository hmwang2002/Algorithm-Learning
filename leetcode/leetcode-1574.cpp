#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size(), right = n - 1;
        while (right && arr[right - 1] <= arr[right])
        {
            right--;
        }
        if (right == 0)
            return 0;
        // 此时arr[right - 1] > arr[right]
        int ans = right;
        for (int left = 0; left == 0 || arr[left - 1] <= arr[left]; left++)
        {
            while (right < n && arr[right] < arr[left])
                right++;
            // 此时 arr[left] <= arr[right]，从left + 1到right - 1可以删除
            ans = min(ans, right - left - 1);
        }
        return ans;
    }
};