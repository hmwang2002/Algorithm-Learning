#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    // ListNode *detectCycle(ListNode *head)
    // {
    //     unordered_set<ListNode *> s;
    //     while(head != nullptr) {
    //         if(s.count(head))
    //             return head;
    //         s.emplace(head);
    //         head = head->next;
    //     }
    //     return nullptr;
    // }

    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                break;
            }
        }
        if(fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};