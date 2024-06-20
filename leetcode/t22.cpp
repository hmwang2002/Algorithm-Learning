#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *fast = head, *slow = dummy;
        while (fast != nullptr && fast->next != nullptr)
        {
            ListNode *tmp = fast;
            fast = fast->next;
            tmp->next = fast->next;
            fast->next = tmp;
            slow->next = fast;
            slow = tmp;
            fast = tmp->next;
        }
        return dummy->next;
    }
};
