#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    vector<vector<string>> res;
    unordered_set<int> cols, diag1, diag2;

    void backtrace(vector<string> &chess, int row, int n)
    {
        if (row == n)
        {
            res.push_back(chess);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            int d1 = row + i, d2 = row - i;
            if (check(i, d1, d2))
            {
                cols.insert(i), diag1.insert(d1), diag2.insert(d2);
                chess[row][i] = 'Q';
                backtrace(chess, row + 1, n);
                chess[row][i] = '.';
                cols.erase(i), diag1.erase(d1), diag2.erase(d2);
            }
        }
    }

    bool check(int col, int d1, int d2)
    {
        if (cols.count(col) || diag1.count(d1) || diag2.count(d2))
        {
            return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chess(n, string(n, '.'));
        backtrace(chess, 0, n);
        return res;
    }
};