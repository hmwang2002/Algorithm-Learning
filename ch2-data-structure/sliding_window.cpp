#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, k;
int a[N], q[N]; // a存储的是值，q存储下标

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int hh = 0, tt = -1;

    // 求最小值
    for (int i = 0; i < n; i++)
    {
        // 判断队头是否已经滑出窗口
        while (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;

        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }

    puts("");

    // 求最大值
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        // 判断队头是否已经滑出窗口
        while (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;

        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }

    return 0;
}