#include <bits/stdc++.h>
#include "datastructure.h"

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

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;
        ListNode *mid = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

    void mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *l1_tmp, *l2_tmp;
        while (l1 != nullptr && l2 != nullptr)
        {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }

    // void reorderList(ListNode *head)
    // {
    //     deque<ListNode *> dq;
    //     ListNode *p = head;
    //     while (p != nullptr)
    //     {
    //         dq.push_back(p);
    //         p = p->next;
    //     }
    //     ListNode *dummy = new ListNode(-1, head);
    //     p = dummy;
    //     bool flag = true;
    //     while (!dq.empty())
    //     {
    //         if (flag)
    //         {
    //             p->next = dq.front();
    //             dq.pop_front();
    //             flag = false;
    //         }
    //         else
    //         {
    //             p->next = dq.back();
    //             dq.pop_back();
    //             flag = true;
    //         }
    //         p = p->next;
    //     }
    //     p->next = nullptr;
    // }
};