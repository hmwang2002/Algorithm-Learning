#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // int rangeBitwiseAnd(int m, int n)
    // {
    //     int shift = 0;
    //     while(m < n){
    //         shift++;
    //         m >>= 1;
    //         n >>= 1;
    //     }
    //     return m <<= shift;
    // }

    // Brian Kernighan 算法
    int rangeBitwiseAnd(int m, int n)
    {
        while (m < n)
        {
            // 抹去最右边的1
            n = n & (n - 1);
        }
        return n;
    }
};