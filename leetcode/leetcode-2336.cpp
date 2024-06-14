#include <bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet
{
    int p = 1;
    set<int> s;

public:
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        if (s.empty())
        {
            int ans = p;
            p++;
            return ans;
        }
        int ans = *s.begin();
        s.erase(s.begin());
        return ans;
    }

    void addBack(int num)
    {
        if (num < p)
        {
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */