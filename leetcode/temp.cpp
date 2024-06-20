#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        vector<int> ne(m);
        for (int i = 1, j = 0; i < m; i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = ne[j - 1];
            }
            if (needle[i] == needle[j])
            {
                j++;
            }
            ne[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = ne[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == m)
            {
                return i - m + 1;
            }
        }
        return -1;
    }
};