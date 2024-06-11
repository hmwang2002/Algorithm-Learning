#include <bits/stdc++.h>

using namespace std;

class MinStack
{
    stack<int> value;
    stack<int> minValue;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        value.push(x);
        if (minValue.empty() || minValue.top() >= x)
        {
            minValue.push(x);
        }
    }

    void pop()
    {
        if (minValue.top() == value.top())
            minValue.pop();
        value.pop();
    }

    int top()
    {
        return value.top();
    }

    int getMin()
    {
        return minValue.top();
    }
};