#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<string> res;
    string s = "";

    const string letters[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};

    void backtracking(string &digits, int i)
    {
        if (i == digits.size())
        {
            res.push_back(s);
            return;
        }
        int index = digits[i] - '0';
        for (int j = 0; j < letters[index].size(); j++)
        {
            s.push_back(letters[index][j]);
            backtracking(digits, i + 1);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return res;
        backtracking(digits, 0);
        return res;
    }
};