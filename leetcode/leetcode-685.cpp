#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int N = 1005;
    vector<int> fa = vector<int>(N, 0);
    int n;

    void init()
    {
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool isSame(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        fa[v] = u;
    }

    vector<int> getRemoveEdge(vector<vector<int>> &edges)
    {
        init();
        for (auto &vec : edges)
        {
            if (isSame(vec[0], vec[1]))
                return vec;
            else
                join(vec[0], vec[1]);
        }
        return {};
    }

    // 删一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>> &edges, int deleteEdge)
    {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++)
        {
            if (i == deleteEdge)
                continue;
            if (isSame(edges[i][0], edges[i][1]))
            { // 构成有向环了，一定不是树
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int inDegree[N];
        memset(inDegree, 0, sizeof inDegree);
        n = edges.size();
        for (int i = 0; i < n; i++)
        {
            inDegree[edges[i][1]]++; // 统计入度
        }
        vector<int> vec; // 记录入度为2的边（如果有的话就两条边）
        // 找入度为2的节点所对应的边，注意要倒序，因为优先返回最后出现在二维数组中的答案
        for (int i = n - 1; i >= 0; i--)
        {
            if (inDegree[edges[i][1]] == 2)
            {
                vec.push_back(i);
            }
        }
        // 处理图中情况1 和 情况2
        // 如果有入度为2的节点，那么一定是两条边里删一个，看删哪个可以构成树
        if (vec.size() > 0)
        {
            if (isTreeAfterRemoveEdge(edges, vec[0]))
            {
                return edges[vec[0]];
            }
            else
            {
                return edges[vec[1]];
            }
        }
        // 处理图中情况3
        // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
        return getRemoveEdge(edges);
    }
};