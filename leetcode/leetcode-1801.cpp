#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

class Solution
{
public:
    const static int mod = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>> &orders)
    {
        priority_queue<pii> buy;
        priority_queue<pii, vector<pii>, greater<>> sell;
        for (auto &o : orders)
        {
            if (o[2] == 0)
            {
                while (!sell.empty())
                {
                    pii t = sell.top();
                    if (o[0] >= t.first)
                    {
                        if (o[1] >= t.second)
                        {
                            o[1] -= t.second;
                            sell.pop();
                        }
                        else
                        {
                            t.second -= o[1];
                            o[1] = 0;
                            sell.pop();
                            sell.emplace(t);
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if (o[1] > 0)
                    buy.emplace(o[0], o[1]);
            }
            else
            {
                while (!buy.empty())
                {
                    pii t = buy.top();
                    if (o[0] <= t.first)
                    {
                        if (o[1] >= t.second)
                        {
                            o[1] -= t.second;
                            buy.pop();
                        }
                        else
                        {
                            t.second -= o[1];
                            o[1] = 0;
                            buy.pop();
                            buy.emplace(t);
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if (o[1] > 0)
                    sell.emplace(o[0], o[1]);
            }
        }
        int res = 0;
        while (!buy.empty())
        {
            pii t = buy.top();
            buy.pop();
            res = (res + t.second) % mod;
        }
        while (!sell.empty())
        {
            pii t = sell.top();
            sell.pop();
            res = (res + t.second) % mod;
        }
        return res;
    }
};
