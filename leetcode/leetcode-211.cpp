#include <bits/stdc++.h>

using namespace std;

struct Trie
{
    vector<Trie *> children;
    bool isEnd;

    Trie()
    {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
};

void insert(Trie *root, string &word)
{
    Trie *node = root;
    for (char c : word)
    {
        if (node->children[c - 'a'] == nullptr)
        {
            node->children[c - 'a'] = new Trie();
        }
        node = node->children[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary
{
    Trie *root;

public:
    WordDictionary()
    {
        root = new Trie();
    }

    void addWord(string word)
    {
        insert(root, word);
    }

    bool search(string word)
    {
        return dfs(word, 0, root);
    }

    bool dfs(const string &word, int index, Trie *node)
    {
        if (index == word.size())
            return node->isEnd;
        char c = word[index];
        if (c == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->children[i] != nullptr)
                {
                    bool res = dfs(word, index + 1, node->children[i]);
                    if (res)
                        return true;
                }
            }
        }
        else
        {
            if (node->children[c - 'a'] != nullptr && dfs(word, index + 1, node->children[c - 'a']))
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */