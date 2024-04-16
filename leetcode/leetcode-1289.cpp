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
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int i1 = 0, i2 = 0, i1_index = -1;
        for (int i = 0; i < n; i++)
        {
            int cur1 = INT_MAX, cur2 = INT_MAX, cur1Index = -1;
            for (int j = 0; j < n; j++)
            {
                int curSum = (j != i1_index) ? i1 + grid[i][j] : i2 + grid[i][j];
                if (curSum < cur1)
                {
                    cur2 = cur1;
                    cur1 = curSum;
                    cur1Index = j;
                }
                else if (curSum < cur2)
                {
                    cur2 = curSum;
                }
            }
            i1 = cur1, i2 = cur2, i1_index = cur1Index;
        }
        return i1;
    }
};