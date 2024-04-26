#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverse(ListNode *pre, ListNode *tail)
    {
        ListNode *cur = pre->next, *nxt = pre->next;
        while (cur->next != tail)
        {
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
        ListNode *tail = head, *pre = dummy;
        while (tail != nullptr)
        {
            for (int i = 0; i < k; i++)
            {
                if (tail == nullptr)
                    return dummy->next;
                tail = tail->next;
            }
            pre = reverse(pre, tail);
        }
        return dummy->next;
    }
};