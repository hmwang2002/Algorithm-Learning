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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }

    // ListNode *deleteDuplicates(ListNode *head)
    // {
    //     if (head == nullptr || head->next == nullptr)
    //         return head;
    //     ListNode *dummy = new ListNode(-1, head);
    //     ListNode *pre = dummy;
    //     ListNode *l = head;
    //     ListNode *r = head->next;
    //     while (r != nullptr)
    //     {
    //         bool flag = false;
    //         while (r != nullptr && l->val == r->val)
    //         {
    //             flag = true;
    //             r = r->next;
    //         }
    //         if (flag)
    //         {
    //             pre->next = r;
    //         }
    //         else
    //         {
    //             pre = pre->next;
    //         }
    //         l = r;
    //         if(r != nullptr)r = r->next;
    //     }
    //     return dummy->next;
    // }
};