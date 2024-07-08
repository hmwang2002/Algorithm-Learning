#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int s = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int cnt = 0;
        for (int i = 0; i < capacity.size(); i++)
        {
            cnt++;
            s -= capacity[i];
            if (s <= 0)
                break;
        }
        return cnt;
    }
};