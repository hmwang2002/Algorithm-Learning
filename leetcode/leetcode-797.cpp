#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<vector<int>> &graph, int i, int n)
    {
        if (i == n - 1)
        {
            res.push_back(path);
            return;
        }
        for (int j = 0; j < graph[i].size(); j++)
        {
            path.push_back(graph[i][j]);
            dfs(graph, graph[i][j], n);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        path.push_back(0);
        dfs(graph, 0, n);
        return res;
    }
};