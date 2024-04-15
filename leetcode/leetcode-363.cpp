#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        { // 枚举上边界
            vector<int> sum(n);
            for (int j = i; j < m; j++)
            {
                for (int c = 0; c < n; c++)
                {
                    sum[c] += matrix[j][c];
                }
                set<int> sumSet{0};
                int s = 0;
                for (int v : sum)
                {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end())
                    {
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int presum[101][101];
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + matrix[i - 1][j - 1];
                for (int c1 = 0; c1 < i; c1++)
                {
                    for (int c2 = 0; c2 < j; c2++)
                    {
                        int sum = presum[i][j] - presum[c1][j] - presum[i][c2] + presum[c1][c2];
                        if (sum <= k)
                            ans = max(sum, ans);
                    }
                }
            }
        }
        return ans;
    }
};