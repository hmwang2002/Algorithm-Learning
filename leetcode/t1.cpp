#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *pre = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *nxt = pre->next;
        for (int i = left; i < right; i++)
        {
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy->next;
    }
};