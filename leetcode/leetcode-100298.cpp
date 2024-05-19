#include <bits/stdc++.h>

using namespace std;

auto _{[]() noexcept
       {
           std::ios::sync_with_stdio(false);
           std::cin.tie(nullptr);
           std::cout.tie(nullptr);
           return 0;
       }()};

class Solution
{
public:
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> mem;

    int dfs(int k, int cur, int jump, bool flag)
    {
        if (cur - k > 1)
            return 0;
        if (mem.count(cur) && mem[cur].count(jump) && mem[cur][jump].count(flag))
            return mem[cur][jump][flag];
        int res = 0;
        if (cur == k)
            res++;
        if (cur > 0 && !flag)
            res += dfs(k, cur - 1, jump, true);
        res += dfs(k, cur + pow(2, jump), jump + 1, false);
        mem[cur][jump][flag] = res;
        return res;
    }

    int waysToReachStair(int k)
    {
        int cur = 1, jump = 0;
        return dfs(k, cur, jump, false);
    }
};
