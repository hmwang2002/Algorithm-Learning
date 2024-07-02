#include <bits/stdc++.h>

using namespace std;

int n, q, x;
vector<int> nums;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    while (q--)
    {
        cin >> x;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (nums[l] != x)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << l << endl;
        }
    }
}