#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int a[9] = {4, 7, 6, 9, 1, 8, 2, 3, 5};
    int b[9] = {4, 7, 6, 9, 1, 8, 2, 3, 5};
    int c[9] = {4, 7, 6, 9, 1, 8, 2, 3, 5};
    nth_element(a, a + 2, a + 9);
    // 将下标为2，也就是第3个数放在正确的位置
    // 也就是求的是第3小
    cout << "第3小是：" << a[2] << endl;
    for (int i = 0; i < 9; i++)
        cout << a[i] << " ";
    puts(""); // 注意下标是从0開始计数的
    // 那么求第3大，就是求第9-3+1小,即第7小
    // 也就是将下标为6的第7个数，放在正确的位置
    nth_element(b, b + 6, b + 9);
    cout << "第3大是：" << b[6] << endl;
    for (int i = 0; i < 9; i++)
        cout << b[i] << " ";
    puts("");                          // 注意下标是从0開始计数的
    nth_element(c, c + 2, c + 9, cmp); // 第一种方法
    // nth_element(c,c+2,c+9,greater<int>()); //第二种方法
    cout << "第3大是：" << c[2] << endl;
    for (int i = 0; i < 9; i++)
        cout << c[i] << " "; // 注意下标是从0開始计数的
    puts("");

    const int n = 5;
    int d[] = {1, 2, 3, 4, 5};
    int p = lower_bound(d, d + n, 3) - d; // 找到第一个 >= 3 的数的下标 2 p = lower_bound(a, a + n, 6) - a; // 返回 n(5)
    cout << p << endl;
}