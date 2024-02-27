#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *fast = dummy;
        int cnt = 0;
        while (cnt != n)
        {
            fast = fast->next;
            cnt++;
        }
        ListNode *pre = dummy;
        while (fast->next != nullptr)
        {
            pre = pre->next;
            fast = fast->next;
        }
        pre->next = pre->next->next;
        return dummy->next;
    }
};