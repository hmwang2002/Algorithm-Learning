#include <bits/stdc++.h>

using namespace std;

int n, m;
int li;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> cnt(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        cin >> li;
        for (int j = 0; j < li; j++)
        {
            int x;
            cin >> x;
            cnt[i][x - 1]++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int xi = 0, yi = 0;
        for (int j = 0; j < n; j++)
        {
            if (cnt[j][i])
            {
                xi++;
                yi += cnt[j][i];
            }
        }
        cout << xi << " " << yi << endl;
    }
}