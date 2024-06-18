#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             { return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto &p : intervals)
        {
            if (!pq.empty() && pq.top() < p[0])
                pq.pop();
            pq.push(p[1]);
        }
        return pq.size();
    }
};