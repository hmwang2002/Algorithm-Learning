#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix[0].size();
        int t = 0, b = matrix.size() - 1;
        while (t <= b)
        {
            int m = (t + b) >> 1;
            if (matrix[m][0] > target)
            {
                b = m - 1;
            }
            else if (matrix[m][n - 1] < target)
            {
                t = m + 1;
            }
            else
            {
                int l = 0, r = n - 1;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (matrix[m][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[m][mid] < target)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                // 注意要break！！！不然死循环！！！
                break;
            }
        }
        return false;
    }
};