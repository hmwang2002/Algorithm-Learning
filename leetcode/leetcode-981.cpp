#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0), std::cout.tie(0);
    }};

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        vector<pair<int, string>> &res = mp[key];
        int l = 0, r = res.size() - 1;
        if (r < 0 || res[0].first > timestamp)
            return "";
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (res[mid].first <= timestamp)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res[r].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
    TimeMap *tmp = new TimeMap();
    tmp->set("foo", "bar", 1);
    tmp->get("foo", 1);
    tmp->get("foo", 3);
    tmp->set("foo", "bar2", 4);
    tmp->get("foo", 4);
    tmp->get("foo", 5);
}