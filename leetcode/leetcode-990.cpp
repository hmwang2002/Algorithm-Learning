#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> f;

    void init()
    {
        f.resize(26);
        for (int i = 0; i < 26; i++)
        {
            f[i] = i;
        }
    }

    int find(int x)
    {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {
        f[find(x)] = find(y);
    }

public:
    bool equationsPossible(vector<string> &equations)
    {
        init();
        for (auto &e : equations)
        {
            if (e[1] == '=')
            {
                int x = e[0] - 'a';
                int y = e[3] - 'a';
                merge(x, y);
            }
        }
        for (auto &e : equations)
        {
            if (e[1] == '!')
            {
                int x = e[0] - 'a', y = e[3] - 'a';
                if (find(x) == find(y))
                {
                    return false;
                }
            }
        }
        return true;
    }
};