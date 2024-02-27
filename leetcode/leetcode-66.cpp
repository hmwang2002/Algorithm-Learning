#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        int c = 1;
        vector<int> res;
        for (int i = n - 1; i >= 0; i--)
        {
            digits[i] += c;
            if (digits[i] == 10)
            {
                digits[i] = 0;
                c = 1;
            }
            else
            {
                c = 0;
                break;
            }
        }
        if (c == 1)
        {
            res.push_back(1);
        }
        for (int i = 0; i < n; i++)
        {
            res.push_back(digits[i]);
        }
        return res;
    }
};