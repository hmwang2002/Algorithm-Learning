#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const static int mod = 1e9 + 7;

    int maximumProduct(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<>> pq(nums.begin(), nums.end());
        while (k--)
        {
            int t = pq.top();
            pq.pop();
            pq.push(t + 1);
        }
        int res = 1;
        while (!pq.empty())
        {
            int t = pq.top();
            pq.pop();
            res = (long long)res * t % mod;
        }
        return res;
    }
};