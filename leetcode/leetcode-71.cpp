#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        auto split = [](const string &s, char delim) -> vector<string>
        {
            vector<string> ans;
            string cur;
            for (char c : s)
            {
                if (c == delim)
                {
                    if (!cur.empty())
                    {
                        ans.push_back(move(cur));
                    }
                }
                else
                {
                    cur += c;
                }
            }
            if (!cur.empty())
            {
                ans.push_back(move(cur));
            }
            return ans;
        };

        vector<string> dir;
        vector<string> names = split(path, '/');
        for (string &name : names)
        {
            if (name == "..")
            {
                if (!dir.empty())
                {
                    dir.pop_back();
                }
            }
            else if (name != ".")
            {
                dir.push_back(name);
            }
        }
        string ans;
        if (dir.empty())
        {
            ans = "/";
        }
        else
        {
            for (string &s : dir)
            {
                ans += "/" + move(s);
            }
        }
        return ans;
    }
};