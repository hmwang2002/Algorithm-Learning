#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int stockManagement(vector<int> &stock)
    {
        int l = 0, r = stock.size() - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (stock[mid] < stock[r])
            {
                r = mid;
            }
            else if (stock[mid] > stock[r])
            {
                l = mid + 1;
            }
            else
            {
                r -= 1;
            }
        }
        return stock[l];
    }
};