#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int r, int target)
{
    if (r < 0)
        return -1;
    int k = INT32_MAX;
    for (int i = r; i >= 0; i--)
    {
        if (a[i] == target)
        {
            return 1;
        }
        if (a[i] < target)
        {
            int res = solve(a, i - 1, target - a[i]);
            if (res != -1)
            {
                k = min(res, k);
                // break;
            }
        }
    }
    return k == INT32_MAX ? -1 : k + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        a.push_back(ai / 2);
        a.push_back(ai);
    }
    sort(a.begin(), a.end());
    int ans = solve(a, a.size() - 1, x);
    cout << ans << endl;
}