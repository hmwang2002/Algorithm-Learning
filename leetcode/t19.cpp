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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *dummy = new ListNode();
        ListNode *res = dummy;
        int add = 0;
        while (p1 || p2)
        {
            int v1 = p1 == nullptr ? 0 : p1->val;
            int v2 = p2 == nullptr ? 0 : p2->val;
            int sum = v1 + v2 + add;
            add = sum / 10;
            sum = sum % 10;
            res->next = new ListNode(sum);
            res = res->next;
            if (p1)
            {
                p1 = p1->next;
            }
            if (p2)
            {
                p2 = p2->next;
            }
        }
        if (add > 0)
        {
            res->next = new ListNode(add);
        }
        return dummy->next;
    }
};