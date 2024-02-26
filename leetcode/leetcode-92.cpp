#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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