#include <iostream>

using namespace std;

int main()
{
    int a, b, p;
    cin >> a >> b >> p;
    int res = 1 % p;
    while (b)
    {
        if (b & 1)
        {
            res = res * 1ll * a % p;
        }
        a = a * 1ll * a % p; // 平方
        b >>= 1;
    }
    cout << res << endl;
    return 0;
}