#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxConstuctiveChar(string &answerKey, int k, char ch)
    {
        int n = answerKey.size();
        int ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < n; r++)
        {
            cnt += answerKey[r] != ch;
            while (cnt > k)
            {
                cnt -= answerKey[l++] != ch;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(maxConstuctiveChar(answerKey, k, 'T'), maxConstuctiveChar(answerKey, k, 'F'));
    }
};