#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // // 动态规划
    // int trap(vector<int> &height)
    // {
    //     int n = height.size();
    //     if (n == 0)
    //         return 0;
    //     vector<int> leftMax(n);
    //     leftMax[0] = height[0];
    //     for (int i = 1; i < n; i++)
    //     {
    //         leftMax[i] = max(height[i], leftMax[i - 1]);
    //     }
    //     vector<int> rightMax(n);
    //     rightMax[n - 1] = height[n - 1];
    //     for (int i = n - 2; i >= 0; i--)
    //     {
    //         rightMax[i] = max(height[i], rightMax[i + 1]);
    //     }
    //     int ans = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         ans += min(leftMax[i], rightMax[i]) - height[i];
    //     }
    //     return ans;
    // }

    // // 单调栈
    // int trap(vector<int> &height)
    // {
    //     int ans = 0;
    //     stack<int> stk;
    //     int n = height.size();
    //     for (int i = 0; i < height.size(); i++)
    //     {
    //         while (!stk.empty() && height[i] > height[stk.top()])
    //         {
    //             int top = stk.top();
    //             stk.pop();
    //             if (stk.empty())
    //             {
    //                 break;
    //             }
    //             int left = stk.top();
    //             int currWidth = i - left - 1;
    //             int currHeight = min(height[left], height[i]) - height[top];
    //             ans += currHeight * currWidth;
    //         }
    //         stk.push(i);
    //     }
    //     return ans;
    // }

    // 双指针
    int trap(vector<int> &height)
    {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right)
        {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if (height[left] < height[right])
            {
                ans += leftMax - height[left];
                ++left;
            }
            else
            {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};