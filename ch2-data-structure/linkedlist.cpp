#include <iostream>

using namespace std;

const int N = 100010;

// head 表示头节点的下标
// e[i]表示节点i的值
// ne[i]表示节点i的next指针是多少
// idx 当前已经用到了哪个点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 将x插到头节点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// 将x插入到下标是k的节点后
void add(int x, int k)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 将下标是k的点后面的点删掉
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m;

    init();
    while (m--)
    {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(x, k - 1);
        }
    }

    for (int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
    cout << endl;

    return 0;
}