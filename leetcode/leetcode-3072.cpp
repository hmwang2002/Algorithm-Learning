#include <bits/stdc++.h>

using namespace std;

class Fenwick
{
    vector<int> tree;

public:
    Fenwick(int n) : tree(n) {}

    void add(int i)
    {
        while (i < tree.size())
        {
            tree[i]++;
            i += i & -i;
        }
    }

    int pre(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += tree[i];
            i &= i - 1;
        }
        return s;
    }
};

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        Fenwick t1(m + 1), t2(m + 1);
        vector<int> a{nums[0]}, b{nums[1]};
        t1.add(lower_bound(sorted.begin(), sorted.end(), nums[0]) - sorted.begin() + 1);
        t2.add(lower_bound(sorted.begin(), sorted.end(), nums[1]) - sorted.begin() + 1);
        for (int i = 2; i < nums.size(); i++)
        {
            int x = nums[i];
            int v = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
            int gc1 = a.size() - t1.pre(v), gc2 = b.size() - t2.pre(v);
            if (gc1 > gc2 || (gc1 == gc2 && a.size() <= b.size()))
            {
                a.push_back(x);
                t1.add(v);
            }
            else
            {
                b.push_back(x);
                t2.add(v);
            }
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};