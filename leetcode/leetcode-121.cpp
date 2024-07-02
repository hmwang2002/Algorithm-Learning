#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        int minprice = INT32_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minprice)
            {
                minprice = prices[i];
            }
            else if (prices[i] - minprice > maxprofit)
            {
                maxprofit = prices[i] - minprice;
            }
        }
        return maxprofit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX, res = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            res = max(res, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return res;
    }
};