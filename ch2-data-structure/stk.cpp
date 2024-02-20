#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int stk[N], tt;
string cmd;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int x;
            cin >> x;
            stk[++tt] = x;
        }
        else if (cmd == "pop")
            tt--;
        else if (cmd == "query")
            printf("%d\n", stk[tt]);
        else if (cmd == "empty")
        {
            if (tt == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}