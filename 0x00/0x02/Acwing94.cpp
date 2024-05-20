#include <bits/stdc++.h>

using namespace std;

vector<int> path;
vector<bool> chosen;
int n;

void backtrace(int k)
{
    if (k == n)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (chosen[i])
            continue;
        chosen[i] = true;
        path.push_back(i);
        backtrace(k + 1);
        chosen[i] = false;
        path.pop_back();
    }
}

int main()
{
    cin >> n;
    chosen.resize(n + 1);
    backtrace(0);
}