#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;

    unordered_set<string> se1;
    unordered_set<string> se2;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        se1.insert(s);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        se2.insert(s);
    }
    int a = 0;
    for (const auto &s : se1)
    {
        if (se2.find(s) != se2.end())
            a++;
    }
    for (const auto &s : se1)
    {
        se2.insert(s);
    }
    cout << a << endl;
    cout << se2.size() << endl;
}