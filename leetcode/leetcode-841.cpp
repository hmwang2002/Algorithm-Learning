#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int cnt = 0;
    vector<bool> visited;

    void dfs(vector<vector<int>> &rooms, int u)
    {
        visited[u] = true;
        cnt++;
        for (int &v : rooms[u])
        {
            if (!visited[v])
            {
                dfs(rooms, v);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        visited.resize(n);
        dfs(rooms, 0);
        return cnt == n;
    }
};