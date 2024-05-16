#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int ans = INT_MAX;
        int w = 0;
        for (int i = 0; i < blocks.size(); i++)
        {
            if (i >= k && blocks[i - k] == 'W')
            {
                w--;
            }
            if (blocks[i] == 'W')
                w++;
            if (i >= k - 1)
            {
                ans = min(ans, w);
            }
        }
        return ans;
    }
};