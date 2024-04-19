#include <bits/stdc++.h>

using namespace std;

auto _{[]() noexcept
       {
           std::ios::sync_with_stdio(false);
           std::cin.tie(nullptr);
           std::cout.tie(nullptr);
           return 0;
       }()};

class Graph
{
private:
    vector<vector<pair<int, int>>> graph;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        this->graph.resize(n);
        for (auto &vec : edges)
        {
            int x = vec[0], y = vec[1], cost = vec[2];
            graph[x].emplace_back(cost, y);
        }
    }

    void addEdge(vector<int> edge)
    {
        graph[edge[0]].emplace_back(edge[2], edge[1]);
    }

    int shortestPath(int node1, int node2)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, node1);
        vector<int> dis(graph.size(), INT_MAX);
        dis[node1] = 0;
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x])
            {
                continue;
            }
            for (auto &[dy, y] : graph[x])
            {
                int new_dis = dx + dy;
                if (dis[y] > new_dis)
                {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }
        return dis[node2] < INT_MAX ? dis[node2] : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */