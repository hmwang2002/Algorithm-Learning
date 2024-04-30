#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const static int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int> &arr)
    {
        int total = 0, sum = 0, even = 1, odd = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            int count = (sum % 2 == 0) ? odd : even;
            total = (total + count) % MOD;
            if (sum % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        return total;
    }
};