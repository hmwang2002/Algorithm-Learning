#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;

int v[N], w[N];
int f[N];

// 拆成01背包问题
int main()
{
    int n, m;
    int a, b, s;
    cin >> n >> m;
    int t = 1;
    while (n--)
    {
        cin >> a >> b >> s;
        while (s--)
        {
            v[t] = a;
            w[t] = b;
            t++;
        }
    }
    for (int i = 1; i < t; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    printf("%d", f[m]);
    return 0;
}