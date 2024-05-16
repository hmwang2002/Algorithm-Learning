#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int sum = 0, cnt = 0;
        threshold = threshold * k;
        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        if (sum >= threshold)
            cnt++;
        for (int i = k; i < arr.size(); i++)
        {
            sum = sum + arr[i] - arr[i - k];
            if (sum >= threshold)
                cnt++;
        }
        return cnt;
    }
};