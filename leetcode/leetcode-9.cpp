#include <iostream>
#include <string>

using namespace std;

// class Solution
// {
// public:
//     bool isPalindrome(int x)
//     {
//         if (x < 0)
//         {
//             return false;
//         }
//         string s = to_string(x);
//         int l = 0, r = s.size() - 1;
//         while (l <= r)
//         {
//             if (s[l++] != s[r--])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int revertedNum = 0;
        while (x > revertedNum)
        {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }
        return revertedNum == x || revertedNum / 10 == x;
    }
};