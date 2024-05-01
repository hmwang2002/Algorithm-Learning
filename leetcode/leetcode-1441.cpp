#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> res;
        stack<int> st;
        int index = 0;
        for (int i = 1; i <= min(target[target.size() - 1], n); i++)
        {
            res.push_back("Push");
            st.push(i);
            if (st.top() == target[index])
            {
                index++;
            }
            else
            {
                res.push_back("Pop");
                st.pop();
            }
        }
        return res;
    }
};