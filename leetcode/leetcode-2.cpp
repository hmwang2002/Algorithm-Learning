#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        int add = 0;
        while (p1 && p2)
        {
            res->next = new ListNode(p1->val + p2->val + add);
            add = 0;
            if (res->next->val >= 10) {
                res->next->val -= 10;
                add = 1;
            }
            res = res->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1) {
            res->next = new ListNode(p1->val + add);
            add = 0;
            if (res->next->val >= 10)
            {
                res->next->val -= 10;
                add++;
            }
            
            res = res->next;
            p1 = p1->next;
        }
        while(p2) {
            res->next = new ListNode(p2->val + add);
            add = 0;
            if (res->next->val >= 10)
            {
                res->next->val -= 10;
                add++;
            }
            res = res->next;
            p2 = p2->next;
        }
        if (add > 0) {
            res->next = new ListNode(add);
        }
        return dummy->next;
    }
};