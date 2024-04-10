#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                right[stk.top()] = i;
                stk.pop();
            }
            left[i] = (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};