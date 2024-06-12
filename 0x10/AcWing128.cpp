#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char op;
int Q, x;
int stkl[N], stkr[N], f[N], sum[N], topl, topr;

void add(int x)
{
    stkl[++topl] = x;
    sum[topl] = sum[topl - 1] + x;
    f[topl] = max(f[topl - 1], sum[topl]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> Q;
    f[0] = INT_MIN;
    while (Q--)
    {
        cin >> op;
        if (op == 'I')
        {
            cin >> x;
            add(x);
        }
        else if (op == 'D')
        {
            if (topl)
                topl--;
        }
        else if (op == 'L')
        {
            if (topl)
                stkr[++topr] = stkl[topl--];
        }
        else if (op == 'R')
        {
            if (topr)
                add(stkr[topr--]);
        }
        else
        {
            cin >> x;
            cout << f[x] << endl;
        }
    }
    return 0;
}