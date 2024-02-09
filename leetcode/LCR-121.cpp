#include <bits/stdc++.h>

using namespace std;


/**
 * @brief Z字形搜索
 * 二分的话不能对行二分，只能在每行对每列二分（不然总会出问题）
 */
class Solution
{
public:
    bool findTargetIn2DPlants(vector<vector<int>> &plants, int target)
    {
        int i = plants.size() - 1, j = 0;
        while (i >= 0 && j < plants[0].size())
        {
            if (plants[i][j] < target)
            {
                j++;
            }
            else if (plants[i][j] > target)
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