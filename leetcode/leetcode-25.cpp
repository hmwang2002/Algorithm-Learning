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
    ListNode *reverse(ListNode *l, ListNode *r)
    {
        ListNode *end = r->next;
        ListNode *cur = l->next;
        ListNode *nxt;
        while (cur->next != end)
        {
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = l->next;
            l->next = nxt;
        }
        return cur;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *l = dummy;
        ListNode *r = dummy;
        int cnt = 0;
        while (r->next != nullptr)
        {
            r = r->next;
            cnt++;
            if (cnt == k)
            {
                l = reverse(l, r);
                r = l;
                cnt = 0;
            }
        }
        return dummy->next;
    }
};