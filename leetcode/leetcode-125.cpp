#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string newstr = "";
        for (char ch : s)
        {
            if (isalnum(ch))
            {
                newstr += tolower(ch);
            }
        }

        int l = 0, r = newstr.size() - 1;
        while (l < r)
        {
            if (newstr[l] != newstr[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};