#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int c, m, n;
unordered_map<int, int> h;
set<int> s;
priority_queue<int, vector<int>, greater<int>> pq;

void bfs()
{
    while (!pq.empty())
    {
        int t = pq.top();
        pq.pop();
        if (h[t] >= 5)
        {
            h[t] = 0;
            set<int>::iterator i;
            i = s.find(t);
            set<int>::iterator i1 = i;
            if (i1 != s.begin())
            {
                i1--;
                h[*i1]++;
                pq.push(*i1);
            }
            if (++i != s.end())
            {
                h[*i]++;
                pq.push(*i);
            }
            s.erase(t);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int x, w;
        cin >> x >> w;
        h[x] = w;
        s.insert(x);
    }

    while (n--)
    {
        int op;
        cin >> op;
        h[op] += 1;
        pq.push(op);
        bfs();
        cout << s.size() << endl;
    }
}