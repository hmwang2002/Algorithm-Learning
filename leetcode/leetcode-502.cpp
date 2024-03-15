#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        int cur = 0;
        priority_queue<int> pq;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.emplace_back(capital[i], profits[i]);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++)
        {
            while (cur < n && arr[cur].first <= w)
            {
                pq.push(arr[cur].second);
                cur++;
            }
            if (!pq.empty())
            {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }
        return w;
    }
};