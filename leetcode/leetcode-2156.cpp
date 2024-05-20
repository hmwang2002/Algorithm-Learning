#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        int n = s.length();
        long long hash = 0, p = 1;
        for (int i = n - 1; i >= n - k; i--)
        {
            hash = (hash * power + (s[i] - 'a' + 1)) % modulo;
            p = p * power % modulo;
        }
        int ans = hash == hashValue ? n - k : 0;
        // 向左滑窗
        for (int i = n - k - 1; i >= 0; i--)
        {
            // 计算新的哈希值，注意 +mod 防止计算出负数
            hash = (hash * power + (s[i] - 'a' + 1) - p * (s[i + k] - 'a' + 1) % modulo + modulo) % modulo;
            if (hash == hashValue)
                ans = i;
        }
        return s.substr(ans, k);
    }
};