#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    vector<vector<string>> res;

    void backtrace(vector<string> &m, int n, int row)
    {
        if (row == n)
        {
            res.push_back(m);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isValid(row, i))
            {
                cols.insert(i);
                diag1.insert(i - row);
                diag2.insert(row + i);
                m[row][i] = 'Q';
                backtrace(m, n, row + 1);
                m[row][i] = '.';
                diag2.erase(row + i);
                diag1.erase(i - row);
                cols.erase(i);
            }
        }
    }

    bool isValid(int i, int j)
    {
        if (cols.count(j) || diag1.count(j - i) || diag2.count(j + i))
        {
            return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> m(n, string(n, '.'));
        backtrace(m, n, 0);
        return res;
    }
};