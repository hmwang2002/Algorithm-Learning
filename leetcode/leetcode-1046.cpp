#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++)
        {
            pq.emplace(stones[i]);
        }
        while (pq.size() >= 2)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x == y)
                continue;
            pq.emplace(x - y);
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
};