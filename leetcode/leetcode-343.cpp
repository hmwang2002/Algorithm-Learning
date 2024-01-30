#include <bits/stdc++.h>

using namespace std;

class NumMatrix
{
    vector<vector<int>> s;
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        s.resize(matrix.size() + 1);
        for (int i = 0; i < s.size(); i++)
            s[i].resize(matrix[0].size() + 1, 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                s[i + 1][j + 1] = matrix[i][j] + s[i][j + 1] + s[i + 1][j] - s[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return s[row2 + 1][col2 + 1] - s[row1][col2 + 1] - s[row2 + 1][col1] + s[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */