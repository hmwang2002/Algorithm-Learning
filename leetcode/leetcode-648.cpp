#include <bits/stdc++.h>

using namespace std;

class Solution
{
    struct Trie
    {
        vector<Trie *> children;
        bool isEnd;
        Trie() : children(26, nullptr), isEnd(false) {}
    };

    string searchPrefix(Trie *root, string &s)
    {
        Trie *cur = root;
        string res;
        for (char c : s)
        {
            if (cur->children[c - 'a'] == nullptr)
                return "";
            cur = cur->children[c - 'a'];
            res += c;
            if (cur->isEnd)
                return res;
        }
        return "";
    }

    void insert(Trie *root, string &s)
    {
        Trie *cur = root;
        for (char c : s)
        {
            if (cur->children[c - 'a'] == nullptr)
            {
                cur->children[c - 'a'] = new Trie();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    vector<string> split(string &s)
    {
        vector<string> res;
        string str;
        stringstream ss(s);
        while (getline(ss, str, ' '))
        {
            res.push_back(str);
        }
        return res;
    }

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie *root = new Trie();
        for (string &prefix : dictionary)
        {
            insert(root, prefix);
        }
        vector<string> words = split(sentence);
        for (string &s : words)
        {
            string ans = searchPrefix(root, s);
            if (!ans.empty())
            {
                s = ans;
            }
        }
        string res = "";
        for (int i = 0; i < words.size(); i++)
        {
            res += words[i];
            if (i != words.size() - 1)
            {
                res += " ";
            }
        }
        return res;
    }
};
