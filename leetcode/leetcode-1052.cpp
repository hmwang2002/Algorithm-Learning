#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        for (int i = 0; i < n; i++)
        {
            customers[i] = grumpy[i] == 1 ? -customers[i] : customers[i];
        }
        int j = -1, cur = 0, min_v = 0;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] < 0)
                cur += customers[i];
            if (i >= minutes && customers[i - minutes] < 0)
            {
                cur -= customers[i - minutes];
            }
            if (i >= minutes - 1 && min_v > cur)
            {
                min_v = cur;
                j = i;
            }
        }
        for (int i = j; i > j - minutes && i >= 0; i--)
        {
            customers[i] = abs(customers[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (customers[i] > 0)
                ans += customers[i];
        }
        return ans;
    }
};