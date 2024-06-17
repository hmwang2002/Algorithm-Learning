#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int cnt = 0;
        while (pq.size() >= 2)
        {
            long long x = pq.top();
            if (x >= k)
            {
                break;
            }
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(x * 2 + y);
            cnt++;
        }
        return cnt;
    }
};