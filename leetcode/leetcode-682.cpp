#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> v;
        for (string &s : operations)
        {
            if (s == "+")
            {
                int n = v.size();
                v.push_back(v[n - 1] + v[n - 2]);
            }
            else if (s == "D")
            {
                v.push_back(v.back() * 2);
            }
            else if (s == "C")
            {
                v.pop_back();
            }
            else
            {
                int num = 0;
                bool flag = true;
                for (int i = 0; i < s.size(); i++)
                {
                    if (s[i] == '-')
                    {
                        flag = false;
                    }
                    else
                    {
                        num = num * 10 + s[i] - '0';
                    }
                }
                if (!flag)
                    num = -num;
                v.push_back(num);
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};