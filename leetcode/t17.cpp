#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = new ListNode(-1, head);
        ListNode *cur = head;
        while (cur->next)
        {
            ListNode *nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return pre->next;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast)
            slow = slow->next;
        slow = reverse(slow);
        ListNode *p = head;
        while (slow != nullptr)
        {
            if (p->val == slow->val)
            {
                p = p->next;
                slow = slow->next;
            }
            else
                return false;
        }
        return true;
    }
};