#include <iostream>
#include <algorithm>

using namespace std;

// 数组不能开太小！！！因为会有很多重复的物品
const int N = 100005;

int v[N], w[N];
int f[N];

// 这题考察背包问题的二进制
int main()
{
    int n, m;
    int a, b, s;
    cin >> n >> m;
    int t = 0;
    while (n--)
    {
        cin >> a >> b >> s;
        for (int k = 1; k <= s; k *= 2)
        {
            v[++t] = k * a;
            w[t] = k * b;
            s -= k;
        }
        if (s > 0)
        {
            v[++t] = s * a;
            w[t] = s * b;
        }
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    printf("%d", f[m]);
    return 0;
}