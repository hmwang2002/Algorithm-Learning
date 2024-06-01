#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int rev = 0;
        while (x > rev)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev == x || rev / 10 == x;
    }
};