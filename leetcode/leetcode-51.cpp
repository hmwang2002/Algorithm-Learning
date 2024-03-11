#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<string>> res;
    unordered_set<int> columns;
    unordered_set<int> diagonals1;
    unordered_set<int> diagonals2;
    void backtrack(int n, int row, vector<string> &chess)
    {
        if (row == n)
        {
            res.push_back(chess);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            int dia1 = row - i;
            int dia2 = row + i;
            if (isValid(i, dia1, dia2))
            {
                columns.insert(i);
                diagonals1.insert(dia1);
                diagonals2.insert(dia2);
                chess[row][i] = 'Q';
                backtrack(n, row + 1, chess);
                chess[row][i] = '.';
                columns.erase(i);
                diagonals1.erase(dia1);
                diagonals2.erase(dia2);
            }
        }
    }

    bool isValid(int col, int dia1, int dia2)
    {
        if (columns.count(col) || diagonals1.count(dia1) || diagonals2.count(dia2))
            return false;
        else
            return true;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chess(n, string(n, '.'));
        backtrack(n, 0, chess);
        return res;
    }
};