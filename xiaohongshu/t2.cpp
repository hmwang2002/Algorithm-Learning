#include <bits/stdc++.h>

using namespace std;

int a[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        a[i] = ai;
    }
    int res = INT32_MAX - 1;
    {
        vector<int> dp(x + 1, INT32_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int t = a[i];
            for (int j = x; j - t / 2 >= 0; --j)
            {
                dp[j] = min(dp[j], dp[j - t / 2] + 1);
            }
        }
        res = min(res, dp[x]);
    }
    for (int i1 = 0; i1 < n; i1++)
    {
        int target = x - a[i1];
        if (target < 0)
            continue;
        vector<int> dp(target + 1, INT32_MAX - 1);
        dp[0] = 0;
        for (int t = 0; t < n; t++)
        {
            if (i1 == t)
                continue;
            int i = a[t];
            for (int j = target; j - i / 2 >= 0; --j)
            {
                dp[j] = min(dp[j], dp[j - i / 2] + 1);
            }
        }
        res = min(res, 1 + dp[target]);
    }
    if (res == INT32_MAX - 1)
        cout << -1 << endl;
    else
        cout << res << endl;
}