#include <bits/stdc++.h>

using namespace std;

pair<int, int> count(string &s, int index)
{
    int cnt = 0;
    for (int i = index; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            pair<int, int> p = count(s, i + 1);
            if(isdigit(s[p.second + 1])) {
                cnt += (p.first * (s[p.second + 1] - '0'));
                i = p.second + 1;
            } else {
                cnt += p.first;
                i = p.second;
            }
        }
        else if (s[i] == ')')
        {
            return {cnt, i};
        }
        else if (s[i] >= '2' && s[i] <= '9')
        {
            cnt += s[i] - '1';
        }
        else
        {
            cnt++;
        }
    }
    return {cnt, s.size() - 1};
}

// 字节番茄后端，没写出来，leetcode 726 hard
int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            pair<int, int> p = count(s, i + 1);
            if (isdigit(s[p.second + 1]))
            {
                cnt += (p.first * (s[p.second + 1] - '0'));
                i = p.second + 1;
            }
            else
            {
                cnt += p.first;
                i = p.second;
            }
        }
        else if (s[i] == ')')
        {
            cout << "error: " << i << endl;
        }
        else if (s[i] >= '2' && s[i] <= '9')
        {
            cnt += s[i] - '1';
        }
        else
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}