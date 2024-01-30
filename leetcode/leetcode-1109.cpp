#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> nums(n);
        for (auto &booking : bookings)
        {
            nums[booking[0] - 1] += booking[2];
            if (booking[1] < n)
            {
                nums[booking[1]] -= booking[2];
            }
        }
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

int main()
{
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    vector<int> res = (new Solution())->corpFlightBookings(bookings, 5);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}