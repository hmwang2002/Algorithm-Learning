#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (const int &n : nums)
        {
            s.insert(n);
        }
        int maxLen = 0;
        for (const int &n : s)
        {
            if (!s.count(n - 1))
            {
                int currentNum = n;
                int len = 1;
                while (s.count(++currentNum))
                {
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};