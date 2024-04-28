#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
    vector<vector<int>> edge;
    vector<int> vis;
    bool valid = true;

    void dfs(int u)
    {
        vis[u] = 1;
        for (int v : edge[u])
        {
            if (!vis[v])
            {
                dfs(v);
                if (!valid)
                    return;
            }
            else if (vis[v] == 1)
            {
                valid = false;
                return;
            }
        }
        vis[u] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edge.resize(numCourses);
        vis.resize(numCourses);
        for (auto &e : prerequisites)
        {
            edge[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                if (!valid)
                {
                    return false;
                }
            }
        }
        return true;
    }
};