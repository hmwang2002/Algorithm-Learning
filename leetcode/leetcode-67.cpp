#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int n = max(a.size(), b.size()), carry = 0;
        for (int i = 0; i < n; i++)
        {
            carry += i < a.size() ? a[i] - '0' : 0;
            carry += i < b.size() ? b[i] - '0' : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if(carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};