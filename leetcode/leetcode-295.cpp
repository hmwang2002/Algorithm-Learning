#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
    priority_queue<int, vector<int>, greater<int>> big_q;
    priority_queue<int> small_q;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (small_q.empty() || num <= small_q.top())
        {
            small_q.push(num);
            if (big_q.size() + 1 < small_q.size())
            {
                big_q.push(small_q.top());
                small_q.pop();
            }
        }
        else
        {
            big_q.push(num);
            if (big_q.size() > small_q.size())
            {
                small_q.push(big_q.top());
                big_q.pop();
            }
        }
    }

    double findMedian()
    {
        if (small_q.size() > big_q.size())
        {
            return small_q.top();
        }
        return (small_q.top() + big_q.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */