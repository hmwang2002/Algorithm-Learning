#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> cnt;
        unordered_set<string> visited;
        for (auto &w : bank)
        {
            cnt.emplace(w);
        }
        if (startGene == endGene)
        {
            return 0;
        }
        if (!cnt.count(endGene))
        {
            return -1;
        }

        queue<pair<string, int>> q;
        q.emplace(startGene, 0);
        visited.emplace(startGene);

        char keys[4] = {'A', 'C', 'G', 'T'};
        while (!q.empty())
        {
            auto a = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (a.first[i] != keys[j])
                    {
                        string s = a.first;
                        s[i] = keys[j];
                        if (cnt.count(s) && !visited.count(s))
                        {
                            if (s == endGene)
                            {
                                return a.second + 1;
                            }
                            q.emplace(s, a.second + 1);
                            visited.emplace(s);
                        }
                    }
                }
            }
        }
        return -1;
    }
};