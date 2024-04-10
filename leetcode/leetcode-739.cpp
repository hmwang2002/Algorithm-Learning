#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int index = s.top();
                s.pop();
                res[index] = i - index;
            }
            s.push(i);
        }
        while(!s.empty()) {
            int index = s.top();
            s.pop();
            res[index] = 0;
        }
        return res;
    }
};