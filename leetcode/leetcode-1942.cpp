#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        unordered_map<int, int> seats;
        priority_queue<int, vector<int>, greater<>> pq;
        vector<pair<int, int>> arrival;
        vector<pair<int, int>> leaving;
        for (int i = 0; i < n; i++)
        {
            arrival.emplace_back(times[i][0], i);
            leaving.emplace_back(times[i][1], i);
        }
        sort(arrival.begin(), arrival.end());
        sort(leaving.begin(), leaving.end());
        for (int i = 0; i < n; i++)
        {
            pq.push(i);
        }
        int j = 0;
        for (auto &&[time, person] : arrival)
        {
            while (j < n && leaving[j].first <= time)
            {
                pq.push(seats[leaving[j].second]);
                j++;
            }
            int seat = pq.top();
            pq.pop();
            seats[person] = seat;
            if (person == targetFriend)
            {
                return seat;
            }
        }
        return -1;
    }
};