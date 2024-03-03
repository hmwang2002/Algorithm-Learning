#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    void handle(Node *&last, Node *&p, Node *&nextStart)
    {
        if (last)
        {
            last->next = p;
        }
        if (!nextStart)
        {
            nextStart = p;
        }
        last = p;
    }

    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        Node *start = root;
        while (start)
        {
            Node *last = nullptr, *nextStart = nullptr;
            for (Node *p = start; p != nullptr; p = p->next)
            {
                if (p->left)
                {
                    handle(last, p->left, nextStart);
                }
                if (p->right)
                {
                    handle(last, p->right, nextStart);
                }
            }
            start = nextStart;
        }
        return root;
    }

    // 层序遍历
    // Node *connect(Node *root)
    // {
    //     if (root == nullptr)
    //         return nullptr;
    //     queue<Node *> q;
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         int n = q.size();
    //         Node *last = nullptr;
    //         for (int i = 0; i < n; i++)
    //         {
    //             Node *f = q.front();
    //             q.pop();
    //             if (f->left)
    //             {
    //                 q.push(f->left);
    //             }
    //             if (f->right)
    //             {
    //                 q.push(f->right);
    //             }
    //             if (i != 0)
    //             {
    //                 last->next = f;
    //             }
    //             last = f;
    //         }
    //     }
    //     return root;
    // }
};