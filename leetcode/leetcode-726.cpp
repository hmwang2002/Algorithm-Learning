#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        int i = 0, n = formula.length();

        auto parseAtom = [&]() -> string
        {
            string atom;
            atom += formula[i++]; // 扫描首字母
            while (i < n && islower(formula[i]))
            {
                atom += formula[i++]; // 扫描首字母后的小写字母
            }
            return atom;
        };

        auto parseNum = [&]() -> int
        {
            if (i == n || !isdigit(formula[i]))
            {
                return 1; // 不是数字，视作 1
            }
            int num = 0;
            while (i < n && isdigit(formula[i]))
            {
                num = num * 10 + int(formula[i++] - '0'); // 扫描数字
            }
            return num;
        };

        stack<unordered_map<string, int>> stk;
        stk.push({});
        while (i < n)
        {
            char ch = formula[i];
            if (ch == '(')
            {
                stk.push({});
                i++;
            }
            else if (ch == ')')
            {
                i++;
                int num = parseNum();
                auto t = stk.top();
                stk.pop();
                for (auto &[k, v] : t)
                {
                    stk.top()[k] += v * num; // 将括号内的原子数乘上num，加到上一层的原子数量中
                }
            }
            else
            {
                string s = parseAtom();
                int num = parseNum();
                stk.top()[s] += num; // 统计原子数量
            }
        }
        auto &atomNum = stk.top();
        vector<pair<string, int>> pairs;
        for (auto &[k, v] : atomNum)
        {
            pairs.emplace_back(k, v);
        }
        sort(pairs.begin(), pairs.end());

        string ans;
        for (auto &p : pairs)
        {
            ans += p.first;
            if (p.second > 1)
            {
                ans += to_string(p.second);
            }
        }
        return ans;
    }
};