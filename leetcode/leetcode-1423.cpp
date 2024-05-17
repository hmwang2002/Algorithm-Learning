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
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int m = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + m, 0);
        int min_s = sum;
        for (int i = m; i < n; i++)
        {
            sum += cardPoints[i] - cardPoints[i - m];
            min_s = min(min_s, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - min_s;
    }
};