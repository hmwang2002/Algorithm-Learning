#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lower_bound(vector<vector<int>> &arr, int end, int target)
    {
        int l = 0, r = end;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid][1] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++)
        {
            int j = lower_bound(arr, i, arr[i][0] + 1);
            dp[i + 1] = max(dp[i], dp[j] + arr[i][2]);
        }
        return dp[n];
    }
};