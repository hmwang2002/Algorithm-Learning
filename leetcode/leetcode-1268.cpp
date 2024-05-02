#include <bits/stdc++.h>

using namespace std;

class Solution
{
    struct Trie
    {
        vector<Trie *> children;
        vector<string> suggests;
        Trie() : children(26, nullptr) {}
    };

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
            if (cur->suggests.size() < 3)
            {
                cur->suggests.push_back(s);
            }
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        Trie *root = new Trie();
        for (string &s : products)
        {
            insert(root, s);
        }
        string s = "";
        vector<vector<string>> res;
        Trie *cur = root;
        for (char c : searchWord)
        {
            s += c;
            if (cur->children[c - 'a'])
            {
                cur = cur->children[c - 'a'];
                res.push_back(cur->suggests);
            }
            else
            {
                break;
            }
        }
        for (int i = res.size(); i < searchWord.size(); i++)
        {
            res.push_back({});
        }
        return res;
    }
};

// 二分
class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        string query;
        auto iter_last = products.begin();
        vector<vector<string>> ans;
        for (char ch : searchWord)
        {
            query += ch;
            auto iter_find = lower_bound(iter_last, products.end(), query);
            vector<string> selects;
            for (int i = 0; i < 3; ++i)
            {
                if (iter_find + i < products.end() && (*(iter_find + i)).find(query) == 0)
                {
                    selects.push_back(*(iter_find + i));
                }
            }
            ans.push_back(move(selects));
            iter_last = iter_find;
        }
        return ans;
    }
};