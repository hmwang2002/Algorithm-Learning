#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1, head);
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *slow = dummy, *fast = dummy->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow->next = fast->next;
            fast->next = fast->next->next;
            slow->next->next = fast;
            slow = fast;
            fast = fast->next;
        }
        return dummy->next;
    }
};