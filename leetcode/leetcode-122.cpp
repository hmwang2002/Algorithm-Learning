#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len < 2)
        {
            return 0;
        }
        // cash：选择持有现金
        // hold：选择持有股票
        // 状态转移：cash → hold → cash → hold → cash → hold → cash
        int cash = 0;
        int hold = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int precash = cash;
            int prehold = hold;
            cash = max(precash, prehold + prices[i]);
            hold = max(prehold, precash - prices[i]);
        }
        return cash;
    }
};