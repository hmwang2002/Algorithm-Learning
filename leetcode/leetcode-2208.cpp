#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        long long total = 0;
        for (int &x : nums)
        {
            total += x;
        }
        double target = total * 1.0 / 2;
        priority_queue<double> pq(nums.begin(), nums.end());
        int cnt = 0;
        double res = 0.0;
        while (1)
        {
            if (res >= target)
            {
                break;
            }
            double t = pq.top();
            pq.pop();
            res += t / 2;
            pq.push(t / 2);
            cnt++;
        }
        return cnt;
    }
};