#include <bits/stdc++.h>

using namespace std;

class Solution
{
    const int L = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        int n = s.length();
        if (n <= L)
            return res;
        int x = 0; // 用二进制表示滑动窗口，总共有20位，因此32位的int可以表示
        for (int i = 0; i < L - 1; i++)
        {
            x = (x << 2) | bin[s[i]];
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n - L; i++)
        {
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << 20) - 1); // 将超过20位的置为0
            cnt[x]++;
            if (cnt[x] == 2)
            {
                res.push_back(s.substr(i, L));
            }
        }
        return res;
    }
};

// class Solution
// {
//     const int L = 10;

// public:
//     vector<string> findRepeatedDnaSequences(string s)
//     {
//         vector<string> res;
//         int n = s.length();
//         if (n <= L)
//             return res;
//         unordered_map<string, int> mp;
//         for (int i = 0; i <= n - L; i++)
//         {
//             string t = s.substr(i, L);
//             mp[t]++;
//             if (mp[t] == 2)
//             {
//                 res.push_back(t);
//             }
//         }
//         return res;
//     }
// };