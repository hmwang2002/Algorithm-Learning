#include <bits/stdc++.h>

using namespace std;

class MapSum
{
    struct Trie
    {
        vector<Trie *> children;
        bool isEnd;
        int val;
        Trie() : children(26, nullptr), isEnd(false), val(0) {}
    };
    Trie *root;
    unordered_map<string, int> cache;

    void insert_(string &key, int val)
    {
        Trie *cur = root;
        for (char c : key)
        {
            if (cur->children[c - 'a'] == nullptr)
            {
                cur->children[c - 'a'] = new Trie();
            }
            cur = cur->children[c - 'a'];
            cur->val += val;
        }
        cur->isEnd = true;
    }

    void replace(string &key, int val, int old)
    {
        Trie *cur = root;
        for (char c : key)
        {
            cur = cur->children[c - 'a'];
            cur->val = cur->val - old + val;
        }
    }

public:
    MapSum()
    {
        root = new Trie();
    }

    void insert(string key, int val)
    {
        if (cache.count(key))
        {
            replace(key, val, cache[key]);
        }
        else
        {
            insert_(key, val);
        }
        cache[key] = val;
    }

    int sum(string prefix)
    {
        Trie *cur = root;
        for (char c : prefix)
        {
            if (cur->children[c - 'a'] == nullptr)
            {
                return 0;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */