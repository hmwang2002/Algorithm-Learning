#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
    struct Trie
    {
        vector<Trie *> children;
        bool isEnd;
        Trie() : children(26, nullptr), isEnd(false) {}
    };

    bool insert(Trie *root, string &s)
    {
        Trie *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (cur->children[s[i] - 'a'] == nullptr && i == s.size() - 1)
            {
                cur->children[s[i] - 'a'] = new Trie();
            }
            else if (cur->children[s[i] - 'a'] == nullptr)
            {
                return false;
            }
            cur = cur->children[s[i] - 'a'];
        }
        cur->isEnd = true;
        return true;
    }

public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        Trie *root = new Trie();
        string ans = "";
        for (string &s : words)
        {
            if (insert(root, s))
            {
                if (s.size() > ans.size())
                {
                    ans = s;
                }
            }
        }
        return ans;
    }
};