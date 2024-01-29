#include <bits/stdc++.h>

using namespace std;

/*
注意题目的数据范围
1000 * log(20000) * 20000 = 14000 * 20000 = 2 * 10^8 会超时限

本题考查多重背包问题的单调队列优化
*/

const int N = 20010;

int n, m;
int f[N], g[N], q[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);

        for (int j = 0; j < v; j++)
        {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v)
            {
                f[k] = g[k];
                if (hh <= tt && k - s * v > q[hh])
                    hh++;
                if (hh <= tt)
                    f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w)
                    tt--;
                q[++tt] = k;
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}