#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    string s;
    vector<string> res;

    void backtrace(int l, int r) {
        if(l < 0 || r < 0 || l > r) {
            return;
        }
        if(l == 0 && r== 0){
            res.push_back(s);
            return;
        }
        if(l > 0) {
            s.push_back('(');
            backtrace(l - 1, r);
            s.pop_back();
        }
        if(l < r) {
            s.push_back(')');
            backtrace(l, r - 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        backtrace(n, n);
        return res;
    }
};