#include <bits/stdc++.h>

using namespace std;

int x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> ma;
    map<int, int> mb;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ma[x]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        mb[x]++;
    }
    int ans = 0;
    int index1 = 0;
    for (auto it = ma.begin(); it != ma.end(); it++)
    {
        index1 += it->second;
        int index2 = 0;
        for (auto it2 = mb.begin(); it2 != mb.end(); it2++) {
            index2 += it2->second;
            ans += index1 * index2 * it->second * it2->second;
        }
    }
    cout << ans << endl;
}