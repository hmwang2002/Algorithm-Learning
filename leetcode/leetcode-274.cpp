#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int l = 0, r = citations.size();
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            int cnt = 0;
            for (int i = 0; i < citations.size(); i++)
            {
                if (citations[i] >= mid)
                    cnt++;
            }
            if (cnt >= mid)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};