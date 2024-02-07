#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        int MOD = 1000000007;
        if (n < 2)
            return n;
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; i++)
        {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }
        return r;
    }
};

/**
 * class Solution {
public:
    const int MOD = 1000000007;

    int fib(int n) {
        if (n < 2) {
            return n;
        }
        vector<vector<long>> q{{1, 1}, {1, 0}};
        vector<vector<long>> res = pow(q, n - 1);
        return res[0][0];
    }

    vector<vector<long>> pow(vector<vector<long>>& a, int n) {
        vector<vector<long>> ret{{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
        vector<vector<long>> c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
            }
        }
        return c;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/solutions/976888/fei-bo-na-qi-shu-lie-by-leetcode-solutio-hbss/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */