#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
    vector<int> res;

    void dfs(int u)
    {
        visited[u] = 1;
        for (int v : edges[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                {
                    return;
                }
            }
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }
        res.push_back(u);
        visited[u] = 2;
    }

    vector<int> test(int n, vector<vector<int>> courses)
    {
        edges.resize(n);
        visited.resize(n);
        for (auto info : courses)
        {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < n && valid; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        if (valid)
        {
            reverse(res.begin(), res.end());
            return res;
        }
        else
        {
            return {};
        }
    }
};

int main()
{
    Solution s;
    int n = 2;
    vector<vector<int>> vec = {{1, 0}};
    vector<int> res = s.test(n, vec);
    for (int i : res)
    {
        cout << i << " ";
    }
}