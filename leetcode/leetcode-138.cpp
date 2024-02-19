#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *cur = head;
        // 复制各节点，并构建拼接链表
        while (cur != nullptr)
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        // 构建各新节点的random指向
        cur = head;
        while (cur != nullptr)
        {
            if (cur->random != nullptr)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // 拆分两链表
        cur = head->next;
        Node *pre = head, *res = head->next;
        while (cur->next != nullptr)
        {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr; // 单独处理原链表尾节点
        return res;
    }
};

// class Solution
// {
// public:
//     Node *copyRandomList(Node *head)
//     {
//         if (head == nullptr)
//             return nullptr;
//         Node *cur = head;
//         unordered_map<Node *, Node *> map;
//         // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
//         while (cur != nullptr)
//         {
//             map[cur] = new Node(cur->val);
//             cur = cur->next;
//         }
//         cur = head;
//         // 4. 构建新链表的 next 和 random 指向
//         while (cur != nullptr)
//         {
//             map[cur]->next = map[cur->next];
//             map[cur]->random = map[cur->random];
//             cur = cur->next;
//         }
//         // 5. 返回新链表的头节点
//         return map[head];
//     }
// };