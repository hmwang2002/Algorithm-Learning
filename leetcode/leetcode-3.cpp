#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_set<char> mset;
        int left = 0;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++) {
            while (mset.find(s[i]) != mset.end()) {
                mset.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
            mset.insert(s[i]);
        }
        return maxLen;
    }
};