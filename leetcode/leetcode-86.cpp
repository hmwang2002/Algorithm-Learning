#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(-1);
        ListNode *smallHead = small;
        ListNode *large = new ListNode(-1);
        ListNode *largeHead = large;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};