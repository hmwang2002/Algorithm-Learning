#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
            return head;
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode *merge(ListNode *l, ListNode *r)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy, *tmp1 = l, *tmp2 = r;
        while (tmp1 != nullptr && tmp2 != nullptr)
        {
            if (tmp1->val <= tmp2->val)
            {
                p->next = tmp1;
                tmp1 = tmp1->next;
            }
            else
            {
                p->next = tmp2;
                tmp2 = tmp2->next;
            }
            p = p->next;
        }
        if (tmp1 != nullptr)
        {
            p->next = tmp1;
        }
        else if (tmp2 != nullptr)
        {
            p->next = tmp2;
        }
        return dummy->next;
    }
};