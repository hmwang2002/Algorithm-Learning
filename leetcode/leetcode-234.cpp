#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *fast = head, *slow = head;
        ListNode *p = nullptr, *pre = nullptr;
        while (fast && fast->next)
        {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
            p->next = pre;
            pre = p;
        }
        if (fast)
        {
            slow = slow->next;
        }
        while (p)
        {
            if (p->val != slow->val)
                return false;
            p = p->next;
            slow = slow->next;
        }
        return true;
    }
};