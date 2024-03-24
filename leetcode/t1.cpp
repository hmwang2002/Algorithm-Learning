#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Trie
{
    vector<Trie *> children;
    bool isEnd;

public:
    Trie()
    {
        children = vector<Trie *>(26);
        isEnd = false;
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char &c : word)
        {
            int index = c - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for(char &c : word) {
            int index = c - 'a';
            if(node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char &c : prefix)
        {
            int index = c - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return true;
    }
};