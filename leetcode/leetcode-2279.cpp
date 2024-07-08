#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        for (int i = 0; i < capacity.size(); i++)
        {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for (int i = 0; i < capacity.size(); i++)
        {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0)
                return i;
        }
        return capacity.size();
    }
};