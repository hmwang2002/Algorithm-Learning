#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        int n = words.size();
        int len = words[0].size();
        unordered_map<string, int> m;
        for (string &word : words)
        {
            m[word]++;
        }
        for (int i = 0; i < len; i++)
        {
            int cnt = 0, left = i, right = i;
            unordered_map<string, int> seen;
            while (right + len <= (int)s.size())
            {
                string w = s.substr(right, len);
                right += len;
                if (m.find(w) != m.end())
                {
                    seen[w]++;
                    cnt++;
                    while (seen[w] > m[w])
                    {
                        string prefix = s.substr(left, len);
                        seen[prefix]--;
                        cnt--;
                        left += len;
                    }
                    if (cnt == n) {
                        res.push_back(left);
                    }
                }
                else
                {
                    left = right;
                    cnt = 0;
                    seen.clear();
                }
            }
        }
        return res;
    }
};