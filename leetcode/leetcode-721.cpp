#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> f;

    void init(int n)
    {
        f.resize(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
        }
    }

    int find(int x)
    {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void merge(int x, int y)
    {
        f[find(x)] = find(y);
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int emailCnt = 0;
        for (auto &account : accounts)
        {
            string &name = account[0];
            int size = account.size();
            for (int i = 1; i < size; i++)
            {
                string &email = account[i];
                if (!emailToIndex.count(email))
                {
                    emailToIndex[email] = emailCnt++;
                    emailToName[email] = name;
                }
            }
        }
        init(emailCnt);
        for (auto &account : accounts)
        {
            string &firstEmail = account[1];
            int firstIndex = emailToIndex[firstEmail];
            int size = account.size();
            for (int i = 2; i < size; i++)
            {
                string &nextEmail = account[i];
                int nextIndex = emailToIndex[nextEmail];
                merge(firstIndex, nextIndex);
            }
        }
        unordered_map<int, vector<string>> indexToEmails;
        for (auto &[email, _] : emailToIndex)
        {
            int index = find(emailToIndex[email]);
            vector<string> &account = indexToEmails[index];
            account.emplace_back(email);
            indexToEmails[index] = account;
        }
        vector<vector<string>> merged;
        for (auto &[_, emails] : indexToEmails)
        {
            sort(emails.begin(), emails.end());
            string &name = emailToName[emails[0]];
            vector<string> account;
            account.emplace_back(name);
            for (auto &email : emails)
            {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }
        return merged;
    }
};