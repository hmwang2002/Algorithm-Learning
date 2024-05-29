#include <bits/stdc++.h>

using namespace std;

int n, m;

int gaussianElimination(vector<vector<double>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int rank = 0;
    for (int col = 0; col < cols; col++)
    {
        int pivotRow = rank;
        while (pivotRow < rows && matrix[pivotRow][col] == 0)
        {
            ++pivotRow;
        }

        if (pivotRow == rows)
            continue;
        if (matrix[rank][col] == 0)
            swap(matrix[rank], matrix[pivotRow]);

        for (int row = rank + 1; row < rows; row++)
        {
            if (matrix[row][col] != 0)
            {
                double factor = matrix[row][col] / matrix[rank][col];
                for (int c = col; c < cols; ++c)
                {
                    matrix[row][c] -= factor * matrix[rank][c];
                }
            }
        }
        ++rank;
    }
    return rank;
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> m;
        unordered_map<string, unordered_map<int, int>> mp;
        for (int i = 0; i < m; i++)
        {
            string s;
            cin >> s;
            string cur;
            for (int j = 0; j < s.size(); j++)
            {
                if (isdigit(s[j]))
                {
                    int k = s[j] - '0';
                    while (j < s.size() - 1 && isdigit(s[j + 1]))
                    {
                        j++;
                        k = k * 10 + s[j] - '0';
                    }
                    mp[cur][i] += k;
                    cur = "";
                }
                else
                    cur += s[j];
            }
        }
        vector<vector<double>> matrix(mp.size(), vector<double>(m, 0.0));
        int index = 0;
        for (auto &p : mp)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[index][i] = p.second[i];
            }
            index++;
        }

        int rank = gaussianElimination(matrix);
        if (rank < m)
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}