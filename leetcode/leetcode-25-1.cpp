#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    ListNode *reverse(ListNode *pre, ListNode *tail)
    {
        ListNode *cur = pre->next, *nxt = pre->next;
        while(cur->next != tail) {
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return cur;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1, head);
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *p = dummy;
        while(p != nullptr) {
            ListNode *tail = p;
            for (int i = 0; i <= k; i++) {
                if(tail == nullptr) {
                    return dummy->next;
                }
                tail = tail->next;
            }
            p = reverse(p, tail);
        }
        return dummy->next;
    }
};