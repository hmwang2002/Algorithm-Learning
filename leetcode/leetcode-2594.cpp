#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        int min_r = *min_element(ranks.begin(), ranks.end());
        long long l = 0, r = 1LL * min_r * cars * cars;
        while (l + 1 < r)
        {
            long long mid = (l + r) / 2, s = 0;
            for (int r : ranks)
            {
                s += sqrt(mid / r);
            }
            (s >= cars ? r : l) = mid;
        }
        return r;
    }
};