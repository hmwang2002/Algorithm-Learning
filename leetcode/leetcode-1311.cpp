#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

using PSI = pair<string, int>;

class Solution
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        int n = friends.size();
        vector<bool> used(n);
        queue<int> q;
        q.push(id);
        used[id] = true;
        for (int _ = 1; _ <= level; _++)
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                int u = q.front();
                q.pop();
                for (int v : friends[u])
                {
                    if (!used[v])
                    {
                        q.push(v);
                        used[v] = true;
                    }
                }
            }
        }
        unordered_map<string, int> freq;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (const string &s : watchedVideos[u])
            {
                freq[s]++;
            }
        }

        vector<PSI> videos(freq.begin(), freq.end());
        sort(videos.begin(), videos.end(), [](const PSI &a, const PSI &b)
             { return a.second < b.second || (a.second == b.second && a.first < b.first); });
        vector<string> ans;
        for (const auto &p : videos)
        {
            ans.push_back(p.first);
        }
        return ans;
    }
};