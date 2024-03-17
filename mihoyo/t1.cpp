#include <bits/stdc++.h>

using namespace std;

int E, R;

int N = 0;

bool check(vector<int> &h, vector<int> &vec, vector<bool> &flag)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (flag[i] && vec[i] >= 0 && vec[i] <= 0.5 * h[i])
        {
            flag[i] = false;
            N++;
            return true;
        }
    }
    return false;
}

int funcE(vector<int> &vec)
{
    int ret = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] -= E;
        if (vec[i] <= 0)
        {
            vec[i] = 0;
        }
        else
        {
            ret++;
        }
    }
    return ret;
}

int funcR(vector<int> &vec)
{
    int ret = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] -= R;
        if (vec[i] <= 0)
        {
            vec[i] = 0;
        }
        else
        {
            ret++;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        N = 0;
        int n;
        cin >> n;
        vector<int> h(n);
        vector<int> vec(n);
        vector<bool> flag(n, true);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
            vec[i] = h[i];
        }
        cin >> E >> R;
        int left = funcE(vec);
        int cnt0 = 1, cnt1 = 0;
        while (left != 0)
        {
            while (N != n && check(h, vec, flag))
            {
                left = funcR(vec);
                cnt1++;
                if(left == 0) {
                    break;
                }
            }
            if (left != 0)
            {
                left = funcE(vec);
                cnt0++;
            }
        }
        cout << cnt0 << " " << cnt1 << endl;
    }
}