#include <bits/stdc++.h>

using namespace std;

struct DLinkedNode
{
    int key, val;
    DLinkedNode *pre;
    DLinkedNode *next;
    DLinkedNode() : key(0), val(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int key, int value) : key(key), val(value), pre(nullptr), next(nullptr) {}
};

class LRUCache
{
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size, capacity;

public:
    LRUCache(int capacity)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if (size > capacity)
            {
                // 超过容量删除尾节点
                DLinkedNode *removed = removeTail();
                size--;
                cache.erase(removed->key);
                delete removed;
            }
        }
        else
        {
            DLinkedNode *node = cache[key];
            node->val = value;
            moveToHead(node);
        }
    }

    void removeNode(DLinkedNode *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(DLinkedNode *node)
    {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
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