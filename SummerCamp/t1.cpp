#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int last = n - 2;
    while (last > 0)
    {
        if (nums[last] > nums[last + 1])
        {
            last--;
        }
        else
        {
            break;
        }
    }
    int t = n - 1;
    while (nums[last] > nums[t])
    {
        t--;
    }
    swap(nums[last], nums[t]);
    reverse(nums.begin() + last + 1, nums.end());
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
}