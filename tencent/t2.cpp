#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    bool isValid(ListNode *head)
    {
        deque<ListNode *> q1;
        deque<ListNode *> q2;
        ListNode *p = head;
        while (p != nullptr)
        {
            if (q1.empty())
            {
                q1.push_back(p);
                p = p->next;
                continue;
            }
            if (p->val > q1.back()->val)
            {
                q1.push_back(p);
                p = p->next;
            }
            else
            {
                break;
            }
        }
        while (p != nullptr)
        {
            if (q2.empty())
            {
                q2.push_back(p);
                p = p->next;
                continue;
            }
            if (p->val > q2.back()->val)
            {
                q2.push_back(p);
                p = p->next;
            }
            else
            {
                return false;
            }
        }
        if(!q2.empty() && q2.back()->val > q1.front()->val)
            return false;
        return true;
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return bool布尔型vector
     */
    vector<bool> canSorted(vector<ListNode *> &lists)
    {
        // write code here
        vector<bool> res;
        for(ListNode *head : lists) {
            res.push_back(isValid(head));
        }
        return res;
    }
};