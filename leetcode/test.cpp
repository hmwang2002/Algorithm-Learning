#include <bits/stdc++.h>

using namespace std;

struct DLinkedNode
{
    int key, val;
    DLinkedNode *pre;
    DLinkedNode *next;
    DLinkedNode() : key(0), val(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {}
};

class LRUCache
{
    int size, capacity;
    DLinkedNode *head, *tail;
    unordered_map<int, DLinkedNode *> mp;

public:
    LRUCache(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail, tail->pre = head;
    }

    int get(int key)
    {
        if (!mp.count(key))
        {
            return -1;
        }
        DLinkedNode *node = mp[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if(mp.count(key)) {
            DLinkedNode *node = mp[key];
            node->val = value;
            moveToHead(node);
        } else {
            DLinkedNode *node = new DLinkedNode(key, value);
            mp[key] = node;
            addToHead(node);
            size++;
            if(size > capacity) {
                DLinkedNode *removed = removeTail();
                size--;
                mp.erase(removed->key);
                delete removed;
            }
        }
    }

    void removeNode(DLinkedNode *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(DLinkedNode *node)
    {
        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
    }

    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */