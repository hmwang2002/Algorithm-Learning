#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int i = 0;
        while (i < n)
        {
            int s = 0;
            int cnt = 0;
            while (cnt < n)
            {
                int j = (i + cnt) % n;
                s += (gas[j] - cost[j]);
                if (s < 0)
                    break;
                cnt++;
            }
            if(cnt == n)
                return i;
            i = i + cnt + 1;
        }
        return -1;
    }
};