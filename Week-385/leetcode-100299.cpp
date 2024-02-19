#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        // 将arr2的所有前缀放入哈希表
        unordered_set<int> st;
        for (int x : arr2)
        {
            for (int y = x; y; y /= 10)
            {
                st.insert(y);
            }
        }
        int ans = 0;
        // 枚举arr1中的所有前缀
        for (int x : arr1)
        {
            int len = 0;
            for (int y = x; y; y /= 10)
                len++;
            for (int i = x; i; i /= 10)
            {
                // 查询哈希表
                if (st.count(i))
                {
                    ans = max(ans, len);
                    break;
                }
                len--;
            }
        }
        return ans;
    }
};