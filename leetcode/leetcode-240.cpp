#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size())
        {
            if (matrix[i][j] < target)
            {
                j++;
            }
            else if (matrix[i][j] > target)
            {
                i--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         for (const auto &row : matrix)
//         {
//             auto it = lower_bound(row.begin(), row.end(), target);
//             if (it != row.end() && *it == target)
//                 return true;
//         }
//         return false;
//     }
// };