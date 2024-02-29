#include <bits/stdc++.h>

using namespace std;

class Trie
{
    vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(string prefix)
    {
        Trie *node = this;
        for (char c : prefix)
        {
            c -= 'a';
            if (node->children[c] == nullptr)
                return nullptr;
            node = node->children[c];
        }
        return node;
    }

public:
    Trie()
    {
        children = vector<Trie *>(26);
        isEnd = false;
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            c -= 'a';
            if (node->children[c] == nullptr)
            {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */