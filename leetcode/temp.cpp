#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res;
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                {
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};