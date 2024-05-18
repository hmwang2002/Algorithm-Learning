#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.length(), m = s2.length();
        if (n > m)
            return false;
        vector<int> cnt(26);
        for (int i = 0; i < n; i++)
        {
            --cnt[s1[i] - 'a'];
        }
        int left = 0;
        for (int right = 0; right < m; right++)
        {
            int x = s2[right] - 'a';
            ++cnt[x];
            while (cnt[x] > 0)
            {
                --cnt[s2[left] - 'a'];
                ++left;
            }
            if (right - left + 1 == n)
                return true;
        }
        return false;
    }
};

int main()
{
    string s1 = "aaa", s2 = "aaaa";
    bool res = (new Solution())->checkInclusion(s1, s2);
    cout << res << endl;
}