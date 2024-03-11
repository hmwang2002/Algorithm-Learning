#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     int totalNQueens(int n)
//     {
//         unordered_set<int> columns, diagonals1, diagonals2;
//         return backtrack(n, 0, columns, diagonals1, diagonals2);
//     }

//     int backtrack(int n, int row, unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2)
//     {
//         if (row == n)
//             return 1;
//         int cnt = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if(columns.find(i) != columns.end()) {
//                 continue;
//             }
//             int diagonal1 = row - i;
//             if(diagonals1.find(diagonal1) != diagonals1.end()) {
//                 continue;
//             }
//             int diagonal2 = row + i;
//             if(diagonals2.find(diagonal2) != diagonals2.end()) {
//                 continue;
//             }
//             columns.insert(i);
//             diagonals1.insert(diagonal1);
//             diagonals2.insert(diagonal2);
//             cnt += backtrack(n, row + 1, columns, diagonals1, diagonals2);
//             columns.erase(i);
//             diagonals1.erase(diagonal1);
//             diagonals2.erase(diagonal2);
//         }
//         return cnt;
//     }
// };

class Solution
{
public:
    int ans = 0;
    vector<bool> col, d, ud; // 列，正对角线(y = x + b)，反对角线(y = -x + b)

    void dfs(int u, int n)
    {
        if (u == n)
        {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++)
        { // 枚举每一列
            if (!col[i] && !d[u - i + n] && !ud[u + i])
            {
                col[i] = d[u - i + n] = ud[u + i] = true;
                dfs(u + 1, n);
                col[i] = d[u - i + n] = ud[u + i] = false;
            }
        }
    }
    int totalNQueens(int n)
    {
        col = vector<bool>(n);
        d = ud = vector<bool>(2 * n);
        dfs(0, n);
        return ans;
    }
};