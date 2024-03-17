#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dfs(vector<ll> &vec, int pre, int cur)
{
    int res = 1;
    for (int i = cur + 1; i < vec.size(); i++)
    {
        if (vec[pre] + vec[i] < 2 * vec[cur])
        {
            res = max(res, dfs(vec, cur, i) + 1);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            res = max(res, dfs(vec, i, j) + 1);
        }
    }
    cout << res << endl;
}