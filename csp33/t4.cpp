#include <bits/stdc++.h>

using namespace std;

int c, m, n;

int check(vector<int> &mp)
{
    for (int i = 0; i < c; i++)
    {
        if (mp[i] >= 5)
            return i;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> m >> n;
    vector<int> mp(c);
    for (int i = 0; i < m; i++)
    {
        int x, w;
        cin >> x >> w;
        mp[x - 1] = w;
    }
    while (n--)
    {
        int p;
        cin >> p;
        p -= 1;
        mp[p]++;
        int mid = check(mp);
        while (mid != -1)
        {
            mp[mid] = 0;
            m--;
            for (int i = mid - 1; i >= 0; i--)
            {
                if (mp[i] > 0)
                {
                    mp[i]++;
                    break;
                }
            }
            for (int i = mid + 1; i < c; i++)
            {
                if (mp[i] > 0)
                {
                    mp[i]++;
                    break;
                }
            }
            mid = check(mp);
        }
        cout << m << endl;
    }
}