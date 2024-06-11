#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

int climb(int n)
{
    int pre = 1, cur = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = pre + cur;
        pre = cur;
        cur = temp;
    }
    return cur;
}

int main()
{
    int res = climb(4);
    cout << res << endl;
}