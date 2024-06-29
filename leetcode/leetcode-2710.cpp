#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        int n = num.size();
        int len = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (num[i] == '0')
                len++;
            else
                break;
        }
        return num.substr(0, n - len);
    }
};