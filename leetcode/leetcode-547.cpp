#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<bool> visited;

    void dfs(vector<vector<int>> &isConnected, int u)
    {
        visited[u] = true;
        for (int i = 0; i < isConnected[u].size(); i++)
        {
            if (isConnected[u][i] == 1 && !visited[i])
            {
                visited[i] = true;
                dfs(isConnected, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        visited.resize(n);
        int provinces = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, i);
                provinces++;
            }
        }
        return provinces;
    }
};