#include <bits/stdc++.h>

using namespace std;

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0 || head->next == nullptr)
            return head;
        int n = 1;
        ListNode *iter = head;
        while (iter->next != nullptr)
        {
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n)
        {
            return head;
        }
        iter->next = head;
        while (add--)
        {
            iter = iter->next;
        }
        ListNode *ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for (int i = 1; i <= 2; i++)
    {
        ListNode *n = new ListNode(i);
        p->next = n;
        p = p->next;
    }
    Solution s;
    ListNode *ans = s.rotateRight(head, 4);
    cout << ans->val << endl;
}