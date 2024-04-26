#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        auto check = [&](long long x)
        {
            long long sum = 0;
            for (int &t : time)
            {
                sum += x / t;
                if (sum >= totalTrips)
                {
                    return true;
                }
            }
            return false;
        };

        long long min_t = *min_element(time.begin(), time.end());
        long long l = min_t, r = min_t * totalTrips;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (check(mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};