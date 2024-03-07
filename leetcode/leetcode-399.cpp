#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find(vector<int> &f, vector<double> &w, int x)
    {
        if (f[x] != x)
        {
            int father = find(f, w, f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = father;
        }
        return f[x];
    }

    void merge(vector<int> &f, vector<double> &w, int x, int y, double val)
    {
        int fx = find(f, w, x);
        int fy = find(f, w, y);
        f[fx] = fy;
        w[fx] = val * w[y] / w[x];
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        int id = 0;

        unordered_map<string, int> variables;
        for (int i = 0; i < n; i++)
        {
            if (variables.find(equations[i][0]) == variables.end())
            {
                variables[equations[i][0]] = id++;
            }
            if (variables.find(equations[i][1]) == variables.end())
            {
                variables[equations[i][1]] = id++;
            }
        }

        vector<int> f(id);
        vector<double> w(id, 1.0);
        for (int i = 0; i < id; i++)
        {
            f[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            merge(f, w, va, vb, values[i]);
        }

        vector<double> ret;
        for (const auto &q : queries)
        {
            double res = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end())
            {
                int ia = variables[q[0]], ib = variables[q[1]];
                int fa = find(f, w, ia), fb = find(f, w, ib);
                if (fa == fb)
                    res = w[ia] / w[ib];
            }
            ret.push_back(res);
        }
        return ret;
    }
};