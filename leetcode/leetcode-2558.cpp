#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < gifts.size(); i++)
        {
            pq.push(gifts[i]);
        }
        for (int i = 0; i < k; i++)
        {
            int t = pq.top();
            pq.pop();
            pq.push(sqrt(t));
        }
        long long res = 0l;
        while (!pq.empty())
        {
            long long t = pq.top();
            pq.pop();
            res += t;
        }
        return res;
    }
};