#include <bits/stdc++.h>

using namespace std;

class Unionfind
{
public:
    vector<int> fa;   // 记录节点的根
    vector<int> rank; // 记录根节点的深度（用于优化）
    int count;        // 记录连通分量的个数
    int rest;         // 记录多余的连接数

    Unionfind(int n) : fa(vector<int>(n)), rank(vector<int>(n)), count(n), rest(0)
    {
        for (int i = 0; i < n; i++)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y)
    {
        int rootx = find(x), rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] < rank[rooty])
            {
                swap(rootx, rooty);
            }
            fa[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx]++;
            count--;
        }
        else
        {
            rest++;
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        Unionfind uf(n);
        for (auto &e : connections)
        {
            uf.merge(e[0], e[1]);
        }
        if (uf.rest < uf.count - 1)
            return -1;
        return uf.count - 1;
    }
};