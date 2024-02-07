#include <bits/stdc++.h>

using namespace std;

const pair<int, string> values[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"},
};

class Solution
{

public:
    string intToRoman(int num)
    {
        string res;
        for (const pair<int, string> &v : values) {
            while(num >= v.first) {
                num -= v.first;
                res += v.second;
            }
            if(num == 0) {
                break;
            }
        }
        return res;
    }
};