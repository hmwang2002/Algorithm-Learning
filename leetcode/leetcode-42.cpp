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
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (l < r)
        {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if (leftMax < rightMax)
            {
                ans += leftMax - height[l];
                l++;
            }
            else
            {
                ans += rightMax - height[r];
                r--;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int ans = 0, l = 0, r = n - 1, pre_max = 0, suf_max = 0;
        while (l < r)
        {
            pre_max = max(pre_max, height[l]);
            suf_max = max(suf_max, height[r]);
            ans += pre_max < suf_max ? pre_max - height[l++] : suf_max - height[r--];
        }
        return ans;
    }
};