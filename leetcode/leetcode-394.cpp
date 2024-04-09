#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int index = 0;

    string getDigit(string &s)
    {
        string res = "";
        while (index < s.size() && isdigit(s[index]))
        {
            res += s[index];
            index++;
        }
        return res;
    }

    string getStr(string &s)
    {
        string res = "";
        while (index < s.size() && isalpha(s[index]))
        {
            res += s[index];
            index++;
        }
        return res;
    }

    int cal(string &digits)
    {
        int res = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            res = res * 10 + (digits[i] - '0');
        }
        return res;
    }

    string decodeString(string s)
    {
        stack<string> stk;
        stk.push("");
        index = 0;
        while (index < s.size())
        {
            if (isalpha(s[index]))
            {
                stk.push(getStr(s));
            }
            else if (isdigit(s[index]))
            {
                stk.push(getDigit(s));
            }
            else if (s[index] == '[')
            {
                index++;
            }
            else
            {
                string s1 = stk.top();
                stk.pop();
                while (!isdigit(stk.top()[0]))
                {
                    s1 = stk.top() + s1;
                    stk.pop();
                }
                string numstr = stk.top();
                stk.pop();
                int num = cal(numstr);
                string pre = "";
                if (!isdigit(stk.top()[0]))
                {
                    pre = stk.top();
                    stk.pop();
                }
                for (int i = 0; i < num; i++)
                {
                    pre += s1;
                }
                stk.push(pre);
                index++;
            }
        }
        string res = stk.top();
        stk.pop();
        while (!stk.empty())
        {
            string pre = stk.top();
            stk.pop();
            pre += res;
            res = pre;
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    string res = s.decodeString(str);
    cout << res << endl;
}