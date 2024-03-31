#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    ListNode *getMid(ListNode *head, ListNode *tail)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    TreeNode *build(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return nullptr;
        ListNode *mid = getMid(head, tail);
        TreeNode *root = new TreeNode(mid->val);
        root->left = build(head, mid);
        root->right = build(mid->next, tail);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        return build(head, nullptr);
    }
};

// class Solution
// {
// public:
//     int getLength(ListNode *head)
//     {
//         int ret = 0;
//         for (; head != nullptr; ++ret, head = head->next)
//             ;
//         return ret;
//     }

//     TreeNode *buildTree(ListNode *&head, int left, int right)
//     {
//         if (left > right)
//         {
//             return nullptr;
//         }
//         int mid = (left + right) / 2;
//         TreeNode *root = new TreeNode();
//         root->left = buildTree(head, left, mid - 1);
//         root->val = head->val;
//         head = head->next;
//         root->right = buildTree(head, mid + 1, right);
//         return root;
//     }

//     TreeNode *sortedListToBST(ListNode *head)
//     {
//         int length = getLength(head);
//         return buildTree(head, 0, length - 1);
//     }
// };