#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_set<char> se = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    bool isValid(string word)
    {
        if (word.size() < 3)
            return false;
        bool flag1 = false, flag2 = false;
        for (char c : word)
        {
            if (isdigit(c) || isalpha(c))
            {
                if (isalpha(c))
                {
                    if (se.count(c))
                    {
                        flag1 = true;
                    }
                    else
                        flag2 = true;
                }
            }
            else
                return false;
        }
        return flag1 && flag2;
    }
};