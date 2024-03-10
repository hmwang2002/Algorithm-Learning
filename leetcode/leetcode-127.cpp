#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     string s, e;
//     set<string> st;

//     int ladderLength(string beginWord, string endWord, vector<string> &wordList)
//     {
//         s = beginWord, e = endWord;
//         for (string &w : wordList)
//         {
//             st.emplace(w);
//         }
//         if (!st.count(endWord))
//             return 0;
//         // 进行双向bfs，寻找ans
//         int ans = bfs();
//         return ans == -1 ? 0 : ans + 1;
//     }

//     int bfs()
//     {
//         queue<string> q1, q2;
//         unordered_map<string, int> mp1, mp2;
//         // d1 代表从起点 beginWord 开始搜索（正向）
//         // d2 代表从结尾 endWord 开始搜索（反向）

//         /*
//          * m1 和 m2 分别记录两个方向出现的单词是经过多少次转换而来
//          * e.g.
//          * m1 = {"abc":1} 代表 abc 由 beginWord 替换 1 次字符而来
//          * m2 = {"xyz":3} 代表 xyz 由 endWord 替换 3 次字符而来
//          */
//         q1.emplace(s);
//         mp1[s] = 0;
//         q2.emplace(e);
//         mp2[e] = 0;

//         /*
//          * 只有两个队列都不空，才有必要继续往下搜索
//          * 如果其中一个队列空了，说明从某个方向搜到底都搜不到该方向的目标节点
//          * e.g.
//          * 例如，如果 d1 为空了，说明从 beginWord 搜索到底都搜索不到 endWord，反向搜索也没必要进行了
//          */
//         while (!q1.empty() && !q2.empty())
//         {
//             int t = -1;
//             // 为了让两个方向的搜索尽可能平均，优先拓展队列内元素少的方向
//             if (q1.size() <= q2.size())
//             {
//                 t = update(q1, mp1, mp2);
//             }
//             else
//             {
//                 t = update(q2, mp2, mp1);
//             }
//             if (t != -1)
//                 return t;
//         }
//         return -1;
//     }

//     // update 代表deque中取出一个单词进行扩展
//     // cur : 当前方向的距离词典， other : 另一个方向上的距离词典
//     int update(queue<string> &que, unordered_map<string, int> &cur, unordered_map<string, int> &other)
//     {
//         while (!que.empty())
//         {
//             string s = que.front();
//             que.pop();
//             int n = s.size();
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < 26; j++)
//                 {
//                     string str = s.substr(0, i) + (char)(j + 'a') + s.substr(i + 1);
//                     if (st.find(str) != st.end())
//                     {
//                         if (cur.count(str))
//                             continue;
//                         if (other.count(str))
//                             return cur[s] + 1 + other[str];
//                         else
//                         {
//                             que.push(str);
//                             cur[str] = cur[s] + 1;
//                         }
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        while (!q.empty())
        {
            auto a = q.front();
            q.pop();
            for (int i = 0; i < a.first.size(); i++)
            {
                string s = a.first;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    s[i] = ch;
                    if (dict.count(s))
                    {
                        if (s == endWord)
                            return a.second + 1;
                        q.push({s, a.second + 1});
                        dict.erase(s); // 从字典中删除，避免重复访问
                    }
                }
            }
        }
        return 0;
    }
};