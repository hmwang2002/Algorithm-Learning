#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *fast = head, *p = dummy;
        while (fast != nullptr && fast->next != nullptr)
        {
            ListNode *tmp = fast;
            fast = fast->next;
            tmp->next = fast->next;
            p->next = fast;
            fast->next = tmp;
            p = tmp;
            fast = tmp->next;
        }
        return dummy->next;
    }
};