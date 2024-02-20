#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int stk[N], tt;

// 单调栈找左边第一个比自己小的情况
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (tt && x <= stk[tt])
            tt--;
        if (tt == 0)
            cout << "-1 ";
        else
            cout << stk[tt] << " ";
        stk[++tt] = x;
    }
    return 0;
}

// 单调栈找右边第一个比自己大的情况
/**
测试用例：右边第一个比我大
6
6 10 3 7 4 12

结果：
10 12 7 12 12 -1
*/
int a[N], res[N];
int main()
{
    freopen("830_RightBigger.in", "r", stdin);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n; i; i--)
    {
        while (tt && a[i] >= stk[tt])
            tt--;
        if (tt == 0)
            res[i] = -1;
        else
            res[i] = stk[tt];
        stk[++tt] = a[i];
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    return 0;
}