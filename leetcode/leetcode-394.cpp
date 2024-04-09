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
                string s1 = getStr(s);
                stk.push(s1);
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
                string numstr = stk.top();
                int num = 1;
                if (isdigit(numstr[0]))
                {
                    stk.pop();
                    num = cal(numstr);
                }
                string pre = stk.top();
                stk.pop();
                for (int i = 0; i < num; i++) {
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

int main() {
    Solution s;
    string str = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    string res = s.decodeString(str);
    cout << res << endl;
}