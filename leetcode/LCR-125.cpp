#include <bits/stdc++.h>

using namespace std;

class CQueue
{
    queue<int> q;

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        q.push(value);
    }

    int deleteHead()
    {
        int ans = -1;
        if (q.size() != 0)
        {
            ans = q.front();
            q.pop();
        }
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */