#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int loopCount = min(2, k) * n;
        int cur = 0, res = 0;
        for (int i = 0; i < loopCount; i++) {
            int v = arr[i % n];
            cur = cur + v > 0 ? cur + v : 0;
            res = max(res, cur);
        }
        if(sum > 0) {
            while(k-- > 2) {
                res = (res + sum) % 1000000007;
            }
        }
        return res % 1000000007;
    }
};