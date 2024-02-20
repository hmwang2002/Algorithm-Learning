#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

// 初始化
void init()
{
    // 0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k)
{
    r[l[k]] = r[k], l[r[k]] = l[k];
}

int main()
{
    init();
    int m, k, x;
    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "L")
        {
            cin >> x;
            // 最左端插入数x
            // 最左端就是表示在0的右侧插入一个数据
            add(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            // 最右端插入数x
            add(l[1], x); // 1号端点的左侧，就是最右端
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1); // idx从2开始，所以下标需要k+1传入才对
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x); // 在这个k的左侧那个元素的右侧插入数据x
        }
        else
        {
            cin >> k >> x;
            add(k + 1, x); // 正常调用
        }
    }
    // 注意双链表的输出方法,0和1是一头一尾，idx从2开始，换言之，
    //  从r[0]就是开始进行遍历，出现1就结尾了
    for (int i = r[0]; ~i; i = r[i])
        printf("%d ", e[i]);
    return 0;
}
