#include <bits/stdc++.h>

using namespace std;

int n, k;

long long a[405];
long long dp[405][405];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] ^ a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            for (int l = j - 1; l < i; l++)
            {
                dp[i][j] = max(dp[i][j], dp[l][j - 1] + (prefix[i] ^ prefix[l]));
            }
        }
    }
    cout << dp[n][k];
}